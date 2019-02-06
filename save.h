#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED


/**
    i : int             :nNom
    f : float           :flNom
    d : double          :dblNom
    c : char            :cNom
    l : long            :lnNom
    ui: unsigned int    : unNomVar
    uf: unsigned float  : unfNomVar
    s : *STRING*
*/

extern void sauvegarde_matrice(int matrice[ ][TAILLE_SUR_MATRICE ]);
extern void sauvegarde_ligne(int largeur, FILE *pFile);

#endif // SAVE_H_INCLUDED
