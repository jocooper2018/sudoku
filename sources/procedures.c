/**
 * @file procedures.c
 * @author LE BOUT Matthieu 1A1
 * @date novembre 2023
 * @brief SAE 1.01 Projet SUDOKU
 * @details Contient les procedures et les fonctions du programme.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../includes/constantes.h"
#include "../includes/types.h"
#include "../includes/prototypes.h"

// Lire le fichier README.md

void init(t_grille grille)
{
    for (int numLigne = 0; numLigne < TAILLE_GRILLE; numLigne++)
    {
        for (int numCol = 0; numCol < TAILLE_GRILLE; numCol++)
        {
            grille[numLigne][numCol].valeur = 0;
            grille[numLigne][numCol].depart = false;
        }
    }
}


bool valeurValide(int valeur)
{
    bool estValide = false;

    if ((valeur >= 0) && (valeur <= TAILLE_GRILLE))
    {
        estValide = true;
    }

    return estValide;
}


/**
 * @fn bool chargerGrille(t_grille grille)
 * @param grille `t_grille` Adresse de la variable qui contiendrat la grille.
 * @brief Demande le nom du fichier qui contient la grille a charger,
 * charge la grille si le fichier existe, puis insere les donnees de la grille
 * dans la variable passe en parametre.
*/
bool chargerGrille(t_grille grille)
{
    bool fileLoadSuccess;

    int grilleTmp[TAILLE_GRILLE][TAILLE_GRILLE];
    // int numeroGrille;

    char nomFichier[30];
    printf("Entrez le numero de la grille : ");
    scanf("%s", nomFichier);



    FILE *f;
    f = fopen(nomFichier, "rb");

    if (f == NULL)
    {
        printf("\n ERREUR sur le fichier %s\n", nomFichier);
        fclose(f);
        fileLoadSuccess = false;
    } 
    else 
    {
        fread(grilleTmp, sizeof(int), TAILLE_GRILLE*TAILLE_GRILLE, f);
        fclose(f);

        for (int numLigne = 0; numLigne < TAILLE_GRILLE; numLigne++)
        {
            for (int numCol = 0; numCol < TAILLE_GRILLE; numCol++)
            {
                grille[numLigne][numCol].valeur = grilleTmp[numLigne][numCol];
                if (grille[numLigne][numCol].valeur == 0)
                {
                    grille[numLigne][numCol].depart = false;
                }
                else
                {
                    grille[numLigne][numCol].depart = true;
                }

                fileLoadSuccess = valeurValide(grilleTmp[numLigne][numCol]);
            }
        }
    }

    return fileLoadSuccess;
}


/**
 * @fn void afficherGrille(t_grille grille)
 * @param grille `t_grille` Grille a afficher.
 * @brief Affiche la grille passe en parametre.
*/
void afficherGrille(t_grille grille)
{
    // printf("     1  2  3   4  5  6   7  8  9\n");
    printf("   ");
    for (int i = 0; i < TAILLE_GRILLE; i++)
    {
        if (i % TAILLE_SOUS_GRILLE == 0)
        {
            printf(" ");
        }
        printf(" %d ", i+1);
    }
    printf("\n");

    for (int i = 0; i < TAILLE_GRILLE; i++)
    {
        if (i % TAILLE_SOUS_GRILLE == 0)
        {
            // printf("   +---------+---------+---------+\n");
            printf("   ");
            for (int j = 0; j < TAILLE_GRILLE; j++)
            {
                if (j % TAILLE_SOUS_GRILLE == 0)
                {
                    printf("+");
                }
                printf("---");
            }
            printf("+\n");
        }
        printf("%d  ", i+1);
        for (int j = 0 ; j < TAILLE_GRILLE ; j++)
        {
            if (j % TAILLE_SOUS_GRILLE == 0)
            {
                printf("|");
            }
            if (grille[i][j].valeur == 0)
            {
                printf(" . ");
            }
            else
            {
                printf(" %d ", grille[i][j].valeur);
            }
        }
        printf("|\n");
    }
    printf("   ");
    for (int j = 0; j < TAILLE_GRILLE; j++)
    {
        if (j % TAILLE_SOUS_GRILLE == 0)
        {
            printf("+");
        }
        printf("---");
    }
    printf("+\n");
}


/**
 * @fn void saisir(int *valeur)
 * @param valeur `int` Adresse de la valeur a saisir.
 * @brief Permet a l'utilisateur d'effectuer une saisie.
 * @details Premet a l'utilisateur de saisir un nombre entier. Si l'utilisateur
 * entre autre chose qu'un nombre entier, la saisie restera active
 * jusqu'a ce que la valeur entrer soit un nombre entier.
*/
void saisir(int *valeur)
{
    char ch[3];
    int x = -1;

    while ((x < 0) || (x > TAILLE_GRILLE))
    {
        scanf("%s", ch);
        while (sscanf(ch, "%d", &x) == 0)
        {
            printf("Veuillez entrer un nombre entier entre 1 et %d\n", TAILLE_GRILLE);
            scanf("%s", ch);
        }
        if ((x < 0) || (x > TAILLE_GRILLE))
        {
            printf("Veuillez entrer un nombre entier entre 1 et %d\n", TAILLE_GRILLE);
        }
    }

    *valeur = x;
}


/**
 * @fn bool grilleComplete(t_grille grille)
 * @param grille `t_grille` Grille dont il faut verifier si elle est complete.
 * @return `bool` `true` si la grille est completement remplie, `false` sinon.
 * @brief Parcours la grille passe en parametre et verifie si elle est pleine.
*/
bool grilleComplete(t_grille grille)
{
    bool estComplete = true;
    int i, j;

    i = 0;
    while ((i < TAILLE_GRILLE) && estComplete)
    {
        j = 0;
        while ((j < TAILLE_GRILLE) && estComplete)
        {
            if (grille[i][j].valeur == 0)
            {
                estComplete = false;
            }
            j++;
        }
        i++;
    }

    return estComplete;
}


/**
 * @fn bool possible(t_grille grille, int numLigne, int numColone, int valeur)
 * @param grille `t_grille` Grille dans laquelle on veut savoir si il est 
 * possible d'inserer une valeur.
 * @param numLigne `int` Numero de la ligne ou inserer une valeur.
 * @param numColone `int` Numero de la colone ou inserer une valeur.
 * @param valeur `int` Valeur a inserer.
 * @return `bool` `true` si il est possible d'inserer la valeur a l'emplacement 
 * donnee, `false` sinon.
 * @brief Permet de verifier si il est possible d'inserer une valeur a un 
 * certain emplacement d'une grille donnee sans enfreindre les regles du sudoku.
*/
bool possible(t_grille grille, int numLigne, int numColone, int valeur)
{
    bool peutInserer = true;
    int i, j;
    int iMax, jMax;

    // Verification sur la ligne et sur la colonne
    i = 0;
    while ((i < TAILLE_GRILLE) && peutInserer)
    {
        if ((grille[numLigne][i].valeur == valeur) ||
            (grille[i][numColone].valeur == valeur))
        {
            peutInserer = false;
        }
        i++;
    }
    // Verification sur le groupe de 9 case
    i = (numLigne / NBR_SOUS_GRILLE) * NBR_SOUS_GRILLE;
    iMax = i + TAILLE_SOUS_GRILLE;
    while ((i < iMax) && peutInserer)
    {
        j = (numColone / NBR_SOUS_GRILLE) * NBR_SOUS_GRILLE;
        jMax = j + TAILLE_SOUS_GRILLE;
        while ((j < jMax) && peutInserer)
        {
            if (grille[i][j].valeur == valeur)
            {
                peutInserer = false;
            }
            j++;
        }
        i++;
    }

    return peutInserer;
}

