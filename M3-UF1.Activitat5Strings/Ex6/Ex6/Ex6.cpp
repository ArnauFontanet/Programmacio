#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100];
    printf("Introdueix una frase: \n");
    gets_s(frase);
    char resultat[100];
    int j = 0;
    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] != ' ' || (j > 0 && resultat[j - 1] != ' ')) {
            resultat[j] = frase[i];
            j++;
        }
    }
    resultat[j] = '\0';
    printf("%s", resultat);
    return 0;
}