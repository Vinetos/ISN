#include <stdio.h>
#include <stdlib.h>

// tranfsorme un entier "nombre" en un tableau et renvoie le nombre de chiffres (ou la taille du tableau
int nombre_a_tableau(int nombre);

int taille_nombre(int nombre);

int main() {

  long long nombre;

  printf("Entrez un nombre: ");
  scanf("%lld", &nombre);

  nombre_a_tableau(nombre);


  return EXIT_SUCCESS;
}

int nombre_a_tableau(int nombre) {

    int taille = taille_nombre(nombre);
    int tableau[taille];
    int indice = 0;
    
    while(nombre != 0) {
        int digit = nombre / 10;
        nombre /= 10;
        tableau[indice] = digit;
        indice++;
    }

    printf("Nombre de digits: %d", taille);

    return 0;
}

int taille_nombre(int nombre) {
    int taille = 0;
    while(nombre != 0)
    {
        nombre /= 10;
        ++taille;
    }

    return taille;
}
