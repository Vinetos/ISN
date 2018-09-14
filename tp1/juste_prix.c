#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Définition des macros
#define MAX  100
#define MIN  1
#define E_AIGU 130

int main()
{
    // Gestion de l'aléatoire
    srand((unsigned int) time(NULL));
    // Entrée de l'utilisateur, prix aléatoire entre MAX et MIN
    int input, price = (unsigned int) (rand() % (MAX - MIN) + MIN);

    while (42) // Boucle infinie
    {
        printf("Quel est votre proposition ?\n>>");
        scanf_s("%d", &input); // On demande un nombre

        if (input == price) // On sort de la boucle infinie si le nombre est le prix
            break;

        // Sinon on affiche le résultat de la comparaison
        printf("C'est plus %s.\n", price < input ? "petit" : "grand");
    }

    printf("Vous avez gagn%c !", E_AIGU); // Affiche gagné avec un « é » correctement affiché
    return EXIT_SUCCESS;
}
