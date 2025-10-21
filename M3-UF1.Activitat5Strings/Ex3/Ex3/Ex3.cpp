#include <string.h>
#include <stdio.h>

int main()
{
    char frase[100];
    printf("Escriu una frase: \n");
    gets_s(frase);
    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u') {
            frase[i] = '.';
        }
    }
    printf("La frase final es: %s", frase);
}