# SUDOKU

## 1 - Avant de compiler
Vérifier que tous les fichiers sources sont présent :
- `sources/main.c`
- `sources/procedures.c`
- `includes/constante.h`
- `includes/types.h`
- `includes/prototypes.h`
- `build.bat`

## 2 - Compilation

### Linux
Ouvrez un terminal dans le répertoire racine du projet et exécutez cette commande :
- `bash build.bat`

### Windows
Ouvrez une invite de comande (`cmd`) ou Windows PowerShell dans le 
dossier racine du projet et exécutez cette commande :
- `.\build.bat`

## 3 - Exécusion du programme

### Linux
Ouvrez un terminal dans le répertoire qui contient l'executable (`sudoku`)
et executez cette commande :
- `./sudoku`

### Windows
Ouvrez une invite de comande (`cmd`) ou Windows PowerShell dans le 
dossier qui contient l'executable (`sudoku.exe`) et executez cette commade :
- `.\sudoku.exe`

## 4 - Charger une grille
Lorsque le programme vous demande `Nom du fichier : `, entrer le nom du fichier
contenant la grille. Les fichiers contenant les grilles sont dans le dossier
`builds`. Les nom de fichiers valide sont :
- `Grille1.sud`
- `Grille2.sud`
- `Grille3.sud`
- `Grille4.sud`
- `Grille5.sud`
- `Grille6.sud`
- `Grille7.sud`
- `Grille8.sud`
- `Grille9.sud`
- `Grille10.sud`

## 5 - Pendant la partie
Pendant la partie, la grille s'affiche et le programme vous demande dans
dans quelle case vous souhaitez insérer un nombre. Une fois que vous avez
décider dans quel case insérer un nombre, entrez les coordonées de celle-ci
en respectant ce format : deux chiffre corespondant au numéro de la ligne et
de la colonne de la case, séparé par un espace, puis apuyez sur `Entrer`.

Si la case que vous avez entrez est valide, le programme vous demandera quel
nombre vous souhaitez insérer.

```
Indice de la case (ligne colonne) : 1 2
Valeur a inserer : 2
```

Si vous vous rendez compte que vous avez entrez le mauvais nombre dans une
case, vous pouvez le changer (à condition qu'il ne s'agisse pas du case de 
départ) en entrant les coordonnées de celle-ci puis la nouvelle valeur :

```
Indice de la case (ligne colonne) : 1 2
Valeur a inserer : 5
```

Vous pouvez également enlever un nombre en entrant la valeur `0`.

```
Indice de la case (ligne colonne) : 1 2
Valeur a inserer : 0
```
