#ifndef VIE__H_INCLUDED
#define VIE__H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAILLE_SOUS_MATRICE 7
#define TAILLE_SUR_MATRICE  9

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

///Protoypes
extern void init(int matrice [][TAILLE_SUR_MATRICE]);
extern int nombre_voisins (int matrice [][TAILLE_SUR_MATRICE],int ligne, int colonne);
extern void mise_a_jour(int matrice[][TAILLE_SUR_MATRICE]);
extern void affiche_matrice(int matrice [][TAILLE_SUR_MATRICE]);
extern void ligne(int largeur);

#endif // VIE__H_INCLUDED
