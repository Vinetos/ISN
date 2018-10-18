#include <stdio.h>
#include <math.h>

// Convertit un nombre decimal en binaire
long long convertDecimalToBinary(int n);

int main() {
    int number;
    printf("Donnez un nombre decimale : ");
    scanf_s("%d", &number);
    printf("Le nombre en binaire est %lld", convertDecimalToBinary(number));
    return 0;
}
/**
 * Convertit un nombre decimal en binaire
 * @param number le nombre decimal
 * @return la valeur en binaire
 */
long long convertDecimalToBinary(int number) {
    long long binary = 0;
    int column_of_digit = 1;
    while (number != 0) {
        int remainder = number % 2;
        number /= 2;
        binary += remainder * column_of_digit;
        column_of_digit *= 10;
    }
    return binary;
}
