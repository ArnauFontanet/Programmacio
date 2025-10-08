#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char text[1000];
    printf("Introdueix una cadena de nomes lletres i espais: \n");
    gets_s(text);
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ' && i == 0) {
            printf("%c", text[i]);
        }
        else if (i > 0 && text[i - 1] == ' ' && text[i] != ' ') {
            printf("%c", text[i]);
        }
    }
}