
#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100];
    int vocals = 0;
    int consonants = 0;
    printf("Escriu una frase: \n");
    gets_s(frase);
    for (int i = 0; i <= strlen(frase); i++) {
        if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' || frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U') {
            vocals += 1;
        }
        else {
            if (frase[i] == ' ' || frase[i] == '.' || frase[i] == ',' || frase[i] == ':' || frase[i] == ';' || frase[i] == '!' || frase[i] == '¡' || frase[i] == '?' || frase[i] == '¿' || frase[i] == '(' || frase[i] == ')') {
                
            }
            else {
                consonants += 1;
            }
        }
    }
    printf("\nEn la frase hi ha un total de %d vocals.\n En la fase hi ha un total de %d consonants.", vocals, consonants-1);

}