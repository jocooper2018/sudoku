/**
 * @file main.c
 * @author LE BOUT Matthieu 1A1
 * @date novembre 2023
 * @brief SAE 1.01 Projet SUDOKU
 * @details Contient le progrmme principale.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../includes/constantes.h"
#include "../includes/types.h"
#include "../includes/prototypes.h"

// Lire le fichier README.md

/**
 * @fn int main()
 * @return `int` Code de sortie du programme.
 * @brief Programme principal.
 * @details Demande a l'utilisateur le nom du fichier contenant la grille a jouer.
 * Puis affiche la grille demande a l'utilisateur de rentrer les coordonees de 
 * la case qu'il souhaite remplir, puis la valeur qu'il souhaite inserer, jusqu'a
 * ce que la grille soit pleine.
*/
int main()
{
    t_grille grille;
    int numLigne,
        numColonne,
        valeur;
    bool grilleCharge = false;

    while (!grilleCharge)
    {
        grilleCharge = chargerGrille(grille);
    }
    while (!grilleComplete(grille))
    {
        afficherGrille(grille);
        printf("Indice de la case (ligne colonne) : ");
        saisir(&numLigne);
        saisir(&numColonne);

        // Les numeros de ligne et de colonnes commence a 1 
        // mais l'indice du tableau commence a 0
        // donc on enleve 1 aux numeros
        numLigne--;
        numColonne--;

        if (grille[numLigne][numColonne].depart)
        {
            printf("IMPOSSIBLE, c'est une case de depart.\n");
        }
        else 
        {
            printf("Valeur a inserer : ");
            saisir(&valeur);
            
            if (possible(grille, numLigne, numColonne, valeur))
            {
                grille[numLigne][numColonne].valeur = valeur;
            }
            else
            {
                printf("Vous ne pouvez pas inserer cet element dans cette case.\n");
            }
        }
    }

    afficherGrille(grille);
    printf("Grille pleine, fin de la partie\n");

    return EXIT_SUCCESS;
}

