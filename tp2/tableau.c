#include <stdio.h>
#include <stdlib.h>

// Prototype des fonctions
// type_renvoye nom_fonction(parametres) ;

// Affiche sur une ligne toutes les valeurs d'un tableau de longueur taille
void affichage_tableau(int tableau[] , int taille);

// Inverse l'ordre des elements dans un tableau
void inverse_tableau(int tableau[] , int taille);

#define ARRAY_LENGTH 10

int main()
{

  // Tableau de test
  int test[ARRAY_LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Affichage du tableau
  affichage_tableau(test, ARRAY_LENGTH);

  // Inversement du tableau
  inverse_tableau(test, ARRAY_LENGTH);

  printf("-----\n");
  affichage_tableau(test, ARRAY_LENGTH);

  return EXIT_SUCCESS;
}

void affichage_tableau(int tableau[] , int taille)
{
    for (int i = 0; i < taille; i++)
        printf("%d : %d\n", i, tableau[i]);
}

void inverse_tableau(int tableau[] , int taille)
{
    int inverse[taille];
    for (int i = 0; i < taille; i++) {
        inverse[taille - i - 1] = tableau[i];// -1 car les tableau commencent à 0 et pas 1
    }

    // Remplace les valeurs du tableau
    for(int i =0; i < taille; i++) {
        tableau[i] = inverse[i];
    }
}
