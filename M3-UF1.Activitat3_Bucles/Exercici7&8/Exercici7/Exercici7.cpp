// Exercici7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int main()
{
    int contra = 9403;
    int pin;
    int intents = 1;
    do {
        printf("Introdueix la contrasenya:\n");
        scanf_s("%d", &pin);
        if (pin == 9403) {
            printf("Contrasenya correcte, la caixa s'ha obert satisfactoriament.\nHa fet servir %d intents.\n", intents);
            return 0;
        }
        else {
            printf("Ho sento, la contrasenya no es correcte. Ha fet servir %d intents de 4.\n", intents);
            intents += 1;
        }

    } while (intents <= 4);

    printf("Ha esgotat els intents.\n");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
