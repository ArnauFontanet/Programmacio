// Exercici9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int main()
{
    int num;
    int digits = 0;
    printf("Introdueix un numero:\n");
    scanf_s("%d", &num);
    if (num == 0) {
        digits = 1;
    }
    else {
        if (num < 0) {
            num = -num;
        }
        int a = num;
        while (a > 0) {
            a /= 10;
            digits += 1;
        }
    }
    printf("El numero introduit te un total de %d digits", digits);
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
