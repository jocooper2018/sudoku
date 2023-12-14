/**
 * @file constantes.h
 * @author LE BOUT Matthieu 1A1
 * @date novembre 2023
 * @brief SAE 1.01 Projet SUDOKU
*/

#ifndef CONSTANTES_H
    #define CONSTANTES_H

    /**
     * @def TAILLE_SOUS_GRILLE 3
     * @brief Taille des sous-grilles.
    */
    #define TAILLE_SOUS_GRILLE 3
    /**
     * @def NBR_SOUS_GRILLE 3
     * @brief Nombre de sous-grilles.
    */
    #define NBR_SOUS_GRILLE TAILLE_SOUS_GRILLE
    /**
     * @def TAILLE_GRILLE 9
     * @brief Taille de la grille du sudoku.
    */
    #define TAILLE_GRILLE (TAILLE_SOUS_GRILLE*TAILLE_SOUS_GRILLE)

#endif

