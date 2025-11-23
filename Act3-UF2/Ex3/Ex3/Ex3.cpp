#include <stdio.h>
#include <math.h>
void operacio(int n1, int n2, char oper, float* resul, int* error);
char menu();
int main()
{

    int num1, num2;
    float resultat = 0;
    int errorr = 0;
    printf("Introdueix el primer nombre: \n");
    scanf_s("%d", &num1);
    printf("Introdueix el segon nombre: \n");
    scanf_s("%d", &num2);
    char op = menu();
    if (op == 's' || op == 'S') {
        printf("\nSortint...\n");
        return 0;
    }
    operacio(num1, num2, op, &resultat, &errorr);
    if (errorr == 1) {
        printf("El resultat de l'operacio es: %.2f", resultat);
    }
    else {
        printf("No s'ha pogut fer l'operacio correctament");
    }
}
void operacio(int n1, int n2, char oper, float* resul, int* error) {
    *error = 1;
    switch (oper) {
    case '+':
        *resul = n1 + n2;
        break;

    case '-':
        *resul = n1 - n2;
        break;

    case '*':
        *resul = n1 * n2;
        break;

    case '/':
        *resul = n1 / n2;
        break;

    case '^':
        *resul = pow(n1, n2);
        break;
    
    case '!':
        /*Lo de tgamma he buscat per google si es podia fer factorial amb la llibreria math.h 
        i m'ha sortit q el factorial d'un num es el mateix que aixo de gamma +1 i ps ho he posat aixi.
        (Se q el factorial s'hauria de fer una funcio que vagi multiplicant un num per un altre que va augmentant fins al nombre donat)*/
        printf("El factorial de %d es: %.2f\n",n1, tgamma(n1 + 1) );
        printf("El factorial de %d es: %.2f\n", n2, tgamma(n2 + 1));


    default:
        *error = -1;
        break;
    }
}

char menu() {
    char op;
    printf("MENU\n+ --> Suma\n- --> Resta\n* --> Multiplicar\n/ --> Dividir\n^ --> Potencia\n! --> Factorial\ns --> Sortir\nTria una opcio:\n");
    scanf_s(" %c", &op, 1);
    return op;
}