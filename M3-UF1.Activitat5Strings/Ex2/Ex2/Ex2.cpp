#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100];  
    printf("Introdueix una frase:\n");
    gets_s(frase);
    int a = 0,e = 0,i = 0,o = 0,u = 0;
    int llargada = strlen(frase);
    printf("La llargada de la frase es de: %d\n", llargada);
    for (int i = 0; i <= strlen(frase); i++) {
        switch (frase[i]) {
        case 'a':
            a += 1;
            break;
        
        case 'e':
            e += 1;
            break;

        case 'i':
            i += 1;
            break;
        
        case 'o':
            o += 1;
            break;

        case 'u':
            u += 1;
            break;
        }
    }
    
    if (a != 0) {
        printf("La lletra a apareix %d cops.\n", a);
    }
    if (e != 0) {
        printf("La lletra e apareix %d cops.\n", e);
    }
    if (i != 0) {
        printf("La lletra i apareix %d cops.\n", i);
    }
    if (o != 0) {
        printf("La lletra o apareix %d cops.\n", o);
    }
    if (u != 0) {
        printf("La lletra u apareix %d cops.\n", u);
    }
}
