/**
 * @file types.h
 * @author LE BOUT Matthieu 1A1
 * @date novembre 2023
 * @brief SAE 1.01 Projet SUDOKU
*/

#ifndef TYPES_H
    #define TYPES_H

    #include <stdbool.h>

    #include "constantes.h"

    typedef struct {
        int valeur;
        bool depart;
    } t_case;

    /**
     * @typedef int t_grille[TAILLE_GRILLE][TAILLE_GRILLE]
     * @brief Tableau de nombre entier (`int`) a deux dimension representant
     * une grille de sudoku.
    */
    typedef t_case t_grille[TAILLE_GRILLE][TAILLE_GRILLE];

#endif

