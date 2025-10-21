#include <stdio.h>
#include <string.h>


int main() {
    char paraula[100];
    char reves[100];
    int j = 0; 

    printf("Escriu una paraula: ");
    gets_s(paraula);

    printf("\nLa paraula introduida es: %s\n", paraula);

    int llarg = strlen(paraula);

    for (int i = llarg - 1; i >= 0; i--) {
        reves[j] = paraula[i]; 
        j++;                   
    }
    reves[j] = '\0'; 

    printf("La paraula al reves es: %s\n", reves);
    
    int palindroma = 0;
    for (int i = 0; i < strlen(paraula); i++) {
        if (paraula[i] != reves[i]) {
            palindroma += 1;
        }
    }
    if (palindroma == 0) {
        printf("La paraula es palindroma\n");
    }
    else {
        printf("La paraula no es palindroma\n");
    }

    return 0;
}