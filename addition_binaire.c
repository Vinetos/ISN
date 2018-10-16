#include <stdlib.h>
#include <stdio.h>

/**
 * Renvoie le nombre de chiffres qui composent le nombre
 *
 * @param chiffres le nombre
 *
 * @return le nombre de chiffres
 */
int nombre_de_chiffres(int chiffres);

/**
 * Transforme un nombre en tableau
 *
 * @param nombre  le nombre à transformer
 * @param tableau le tableau à remplir
 * @param taille  La taille du chiffre
 */
void nombre_en_tableau(int nombre, int tableau[], int taille);

int addition(int b1, int b2);

int main() {
    while (42) {
        int nombreBinaire1, nombreBinaire2;
    printf("Entrer un nombre binaire : ");
    scanf("%d", &nombreBinaire1);

    printf("Entrer second nombre binaire : ");
    scanf("%d", &nombreBinaire2);

    // On prend le plus grand nombre de chiffres pour calculer
    int nombre_chiffres = nombre_de_chiffres(nombreBinaire1);
    if (nombre_chiffres < nombre_de_chiffres(nombreBinaire2)) {
        nombre_chiffres = nombre_de_chiffres(nombreBinaire2);
    }

    int tableau1[nombre_chiffres], tableau2[nombre_chiffres], total[nombre_chiffres+1];
    // On remplit les tableaux correpsondant aux nombres binaires
    nombre_en_tableau(nombreBinaire1, tableau1, nombre_chiffres);
    nombre_en_tableau(nombreBinaire2, tableau2, nombre_chiffres);

    int retenue = 0;
    for (int indice = 0; indice < nombre_chiffres; indice++) {
        int chiffre_1 = tableau1[indice];
        int chiffre_2 = tableau2[indice];
        int somme = chiffre_1 + chiffre_2 + retenue;
        if(somme > 1) {
            retenue = 1;
            total[indice] = (somme == 3) ? 1 : 0;
        } else {
            retenue = 0;
            total[indice] = somme;
        }
    }
    total[nombre_chiffres] = retenue;

    for (int indice = nombre_chiffres; indice > 0; indice--) {
        printf("%d", total[indice]);
    }
    printf("\n");
    }
    return EXIT_SUCCESS;
}

int nombre_de_chiffres(int chiffre) {
    if (chiffre == 0)
        return 1;
    int taille = 0;
    while (chiffre > 0) {
        chiffre /= 10;
        taille++;
    }
    return taille;
}


void nombre_en_tableau(int nombre, int tableau[], int taille) {
    int indice = 0;
    if(nombre == 0) {
        tableau[indice] = 0;
        return;
    }
    while(nombre > 0) {
        tableau[indice] = nombre%10;
        nombre /= 10;
        indice++;
    }
}

int addition(int b1, int b2) {
    return 0;
}
