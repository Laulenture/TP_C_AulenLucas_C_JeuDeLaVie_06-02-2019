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

void sauvegarde_matrice(int matrice[ ][TAILLE_SUR_MATRICE ]) {

    FILE *pFile;
    int nI,nJ;

    if ((pFile=fopen("vie.txt", "a"))==NULL){

        perror("Erreur de creation de fichier\n");

    } else {
        sauvegarde_ligne(7,pFile);
        for(nI=1; nI<=TAILLE_SOUS_MATRICE; nI++) {
            for(nJ=1; nJ<= TAILLE_SOUS_MATRICE; nJ++){
                if (matrice[nI][nJ]==1){
                    fputs("|O", pFile);
                } else{
                    fputs("| ", pFile);
                }
            }
            fputs("|\n", pFile);
            sauvegarde_ligne(TAILLE_SOUS_MATRICE,pFile);
        }
    }
}

void sauvegarde_ligne(int largeur, FILE *pFile){

    int nI;
    for(nI=0; nI<largeur; nI++){
        fputs("+-", pFile);
    }
    fputs("+\n", pFile);
}
