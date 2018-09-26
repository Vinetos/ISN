#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>

/**
 * Remplis un tableau avec chaque chiffre qui compose number
 * @param number Le nombre à transformer (int64_t = nombre sur 64 bits)
 * @param array  Le tableau à remplir
 * @param length Le nombre de chiffres qui composent le nombre (uint8_t = nombre sur un octet)
 */
void getDigitsRec(int64_t number, int *array, uint8_t length) {
    if (number > 9)
        getDigitsRec(number / 10, array, length - 1);
    array[length] = (number % 10);
}

int main() {
    int64_t number = 0;
    printf("Entrez un nombre: ");
    scanf_s("%" SCNd64, &number);
    // Si le nombre est négatif, on ignore le signe
    if (number < 0)
        number = -number;
    // Le nombre de chiffres qui composent le nombre
    uint8_t length = !number ? 1 : log10(number) + 1;
    // Peut se traduire par :
//    if(number == 0) {
//        length = 1;
//    } else {
//        On tronque log(number) à l'unité, + 1 car
//        log10(1->9) => 0, log10(10->99) => 1, log10(100->199) => 3, etc...
//        length = log(number) + 1;
//    }

    // Tableau des chiffres
    int array[length];
    // Remplissage du tableau
    getDigitsRec(number, array, length - 1);// Les tableaux commencent à 0

    // Affichage du contenu du tableau
    for (uint8_t i = 0; i < length; i++)
        printf("[%u]: %d\n", i, array[i]);
    return EXIT_SUCCESS;
}
