#include <stdio.h>
#include <string.h>

int main() {
    char frase[1000];
    char paraula[100];
    int j = 0;
    printf("Introduce una frase: ");
    gets_s(frase);

    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ') { 
            paraula[j] = frase[i];
            j++;
        }
        else {
            if (j > 0) {
                paraula[j] = '\0';
                printf("%s, llargada: %d\n", paraula, j);
                j = 0;
            }
        }
    }
    if (j > 0) {
        paraula[j] = '\0';
        printf("%s, llargada: %d\n", paraula, j);
    }
    return 0;
}