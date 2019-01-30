#include <stdio.h>
#include <stdlib.h>
#include "vie.h"

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


/**
  * BUT : Initialisation de la matrice
  * ENTREE :
  * SORTIE :
  */
void init(int matrice[][TAILLE_SUR_MATRICE]){

    int nI,nJ;
    for(nI=0; nI<TAILLE_SUR_MATRICE; nI++){
        for(nJ=0; nJ<TAILLE_SUR_MATRICE; nJ++){
            if (nI<=nJ && nI>0 && nJ<=7)
                matrice[nI][nJ]=1;
            else
            matrice[nI][nJ]=0;
        }
    }
   /* On pourrait aussi faire une initialisation aléatoire */
}

/**
  * BUT : Calcul du nombre de voisins vivants
  * ENTREE :
  * SORTIE :
  */
int nombre_voisins (int matrice[][TAILLE_SUR_MATRICE ],int ligne, int colonne) {

    int compte=0; /* compteur de cellules */
    int nI,nJ;
/* On additionne les 9 cellules centrées en ligne,colonne */
    for (nI=ligne-1;nI<=ligne+1;nI++){
        for(nJ=colonne-1;nJ<=colonne+1;nJ++){
            compte=compte+matrice[nI][nJ];
        }
    }
    /* Puis on retire celle du milieu... */
    compte -= matrice[ligne][colonne];
    return compte;
}

/**
  * BUT : Correspond à l'étape n+1
  * ENTREE :
  * SORTIE :
  */
void mise_a_jour(int matrice[ ][TAILLE_SUR_MATRICE ]) {

    int nI,nJ;
    int nbr_voisins;
    int matrice_densite[TAILLE_SOUS_MATRICE][TAILLE_SOUS_MATRICE];
    /* matrice qui comptabilise le nombre de voisins */
    /* et cela, case par case */
    for(nI=0; nI< TAILLE_SOUS_MATRICE; nI++){
        for(nJ=0; nJ< TAILLE_SOUS_MATRICE; nJ++){
            matrice_densite[nI][nJ]=nombre_voisins(matrice,nI+1,nJ+1);
        }
    }

    /* nI+1 et nJ+1 car on passe de la SOUS_MATRICE à la MATRICE   */

    for(nI=0; nI< TAILLE_SOUS_MATRICE; nI++){
        for(nJ=0; nJ< TAILLE_SOUS_MATRICE; nJ++) {
            nbr_voisins=matrice_densite[nI][nJ];
            if(nbr_voisins==2){
                matrice[nI+1][nJ+1]=1;
            } else if (nbr_voisins==0 || nbr_voisins==4){
                matrice[nI+1][nJ+1]=0;
            }
        }
    }
}

/**
  * BUT : Affichage à l'écran des cellules vivantes
  * ENTREE :
  * SORTIE :
  */
void affiche_matrice(int matrice[ ][TAILLE_SUR_MATRICE ]) {

    int nI,nJ;
    for(nI=1; nI<=TAILLE_SOUS_MATRICE; nI++) {
        ligne(7);
        for(nJ=1; nJ<= TAILLE_SOUS_MATRICE; nJ++){
            if (matrice[nI][nJ]==1){
                printf("|%c",'*');
            } else{
                printf("|%c",'|');
            }
        }
        printf("|\n");
    }
    ligne(TAILLE_SOUS_MATRICE);
}

/**
  * BUT : Tracé d'une ligne
  * ENTREE :
  * SORTIE :
  */
void ligne(int largeur) {

    int nI;
    for(nI=0; nI<largeur; nI++){
        printf("+-");
    }
    printf("+\n");
}

