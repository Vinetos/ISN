#include <stdio.h>
#include <math.h>

// Convertit un nombre binaire en decimal
int convertBinaryToDecimal(long long n);

int main() {
    long long number;
    printf("Donnez un nombre binnaire: ");
    scanf_s("%lld", &number);
    printf("Le nombre est %d", convertBinaryToDecimal(number));
    return 0;
}
/**
 * Convertit un nombre binaire en decimal
 * @param number le nombre binaire
 * @return la valeur en decimal
 */
int convertBinaryToDecimal(long long number) {
    int decimalNumber = 0, power = 0;
    while (number != 0) {
        int remainder = number % 10;
        number /= 10;
        decimalNumber += remainder * pow(2, power);
        ++power;
    }
    return decimalNumber;
}
