#include <stdlib.h>
#include <stdio.h>

/**
 * Renvoie le nombre de chiffres qui composent le nombre
 *
 * @param number le nombre
 *
 * @return le nombre de chiffres
 */
int countDigits(int number);

/**
 * Alloue la mémoire nécessaire pour un tableau d'entiers
 * @param length la taille du tableau
 * @return le tableau
 */
void *intArray(int length);

/**
 * Transforme un nombre en tableau
 *
 * @param number  le nombre à transformer
 * @param array    le tableau à remplir
 */
void intToArray(int number, int array[]);

int main() {
    // Entrés utilisateurs
    int binaryNumber1, binaryNumber2;
    printf("Addition de deux nombres binaires (bit de poids faible le plus a droite) \n");
    printf("Entrer un nombre binaire : ");
    scanf_s("%d", &binaryNumber1);
    printf("Entrer second nombre binaire : ");
    scanf_s("%d", &binaryNumber2);

    // On compte le nombre de bits et on prend le nombre le plus grand
    int bitCount = countDigits(binaryNumber1);
    if (bitCount < countDigits(binaryNumber2))
        bitCount = countDigits(binaryNumber2);

    // Pointeurs qui serviront de tableaux
    int *binaryNumberArray1 = intArray(bitCount);
    int *binaryNumberArray2 = intArray(bitCount);
    int *total = intArray(bitCount + 1); // +1 parce qu'il peut avoir une retenue donc un bit de plus

    // On remplit les tableaux correpsondant aux nombres binaires
    intToArray(binaryNumber1, binaryNumberArray1);
    intToArray(binaryNumber2, binaryNumberArray2);

    // On fait l'addition des nombres binaires
    int carry = 0;
    for (int index = 0; index < bitCount; index++) {
        int digits1 = binaryNumberArray1[index];
        int digits2 = binaryNumberArray2[index];
        int sum = digits1 + digits2 + carry;

        if (sum > 1) {// On a soit 1 + 1 soit 1 + 1 + 1 (retenue)
            carry = 1; // On crée une retenue pour l'addiction suivante
            total[index] = (sum == 3) ? 1 : 0; // Si la somme vaut trois, on place un 1 sinon 0
        } else {
            carry = 0; // La somme vaut 0 ou 1 donc par de retenue
            total[index] = sum;
        }
    }
    // On ajoute la retenue finale
    total[bitCount] = carry;

    // On affiche le tableau (remplit à l'envers)
    printf("Resultat: ");
    for (int index = bitCount; index >= 0; index--)
        printf("%d", total[index]);

    // On libère la mémoire
    free(binaryNumberArray1);
    free(binaryNumberArray2);
    free(total);

    return EXIT_SUCCESS;
}

int countDigits(int number) {
    // On gère le cas où le nombre vaut 0
    if (number == 0)
        return 1;
    // On compte le nombre de bits
    int size = 0;
    while (number > 0) {
        // Le nombre est considérer en base 10 par l'ordinateur
        number /= 10;
        size++;
    }
    return size;
}

void *intArray(int length) {
    // Permet d'allouer un la mémoire pour x fois la taille d'un int (= tableau de int)
    return malloc(length * sizeof(int));
}

void intToArray(int number, int array[]) {
    int index = 0;
    // On gère le cas où le nombre vaut 0
    if (number == 0) {
        array[index] = 0;
        return;
    }
    while (number > 0) {
        // Le nombre est considérer en base 10 par l'ordinateur
        array[index] = number % 10;
        number /= 10;
        index++;
    }
}
