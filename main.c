#include <stdio.h>
#include <stdlib.h>
#include "vie.h"
#include "save.h"

/**
    i : int             :nVar
    f : float           :flVar
    d : double          :dblVar
    c : char            :cVar
    l : long int        :lnVar
    ll: long long int   :llnVar
    L : double long     :ldblVar
    h : short int       :srVar
    ui: unsigned int    :unVar
    uf: unsigned float  :unfVar
    s : *STRING*
    * : *POINTEUR*      :pVar
*/

void init(int matrice [][TAILLE_SUR_MATRICE ]);
int nombre_voisins (int matrice [][TAILLE_SUR_MATRICE ],int ligne, int colonne);
void mise_a_jour(int matrice[][TAILLE_SUR_MATRICE ]);
void affiche_matrice(int matrice [][TAILLE_SUR_MATRICE ]);
void ligne(int largeur);

/**
  * BUT :
  * ENTREE :
  * SORTIE :
  */
int main( ) {
    int nI;
    int nbr_cycles;
    int matrice[TAILLE_SUR_MATRICE] [TAILLE_SUR_MATRICE ];
    char s[2];
    printf("Nombre de cycles : ");
    scanf("%i",&nbr_cycles);
    init(matrice);
    printf("La population au départ : \n");
    affiche_matrice(matrice);
    printf("Pressez sur ENTER pour continuer...\n");
    gets(s);
    for(nI=0; nI<nbr_cycles; nI++){
        mise_a_jour (matrice);
        printf("La population après %d cycles: \n", nI+1);
        affiche_matrice (matrice);
        sauvegarde_matrice(matrice);
        printf("Pressez sur ENTER pour continuer...\n");
        gets(s);
    }
    return 0;
}

