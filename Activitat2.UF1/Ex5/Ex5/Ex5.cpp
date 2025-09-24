// Ex5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int main()
{
    int color;
    float preuinici, descompte, final;
    printf("Introdueix el preu inicial de la seva compra: \n");
    scanf_s("%f", &preuinici);
    printf("Introdueixi el color de la pilota que li ha sortit:\n 1-Blanc\n 2-Verd\n 3-Groc\n 4-Blau\n 5-Vermell\n");
    scanf_s("%d", &color);

    switch (color) {
        case 1:
            descompte = 0;
            break;
        case 2:
            descompte = 10;
            break;
        case 3:
            descompte = 25;
            break;
        case 4:
            descompte = 50;
            break;
        case 5:
            descompte = 100;
            break;
        default:
            printf("Ha introduit un nombre incorrecte.");
            return 0;
            break;
    }
    final = preuinici -  (preuinici *(descompte / 100));
    printf("El seu preu final amb el descompte es de: %f", final);
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
