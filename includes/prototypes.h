/**
 * @file prototypes.h
 * @author LE BOUT Matthieu 1A1
 * @date novembre 2023
 * @brief SAE 1.01 Projet SUDOKU
*/

#ifndef PROTOTYPES_H
    #define PROTOTYPES_H

    #include <stdbool.h>

    #include "types.h"

    void afficherGrille(t_grille grille);
    void saisir(int *valeur);

    bool chargerGrille(t_grille grille);
    bool possible(t_grille grille, int numLigne, int numColone, int valeur);
    bool grilleComplete(t_grille grille);

#endif

