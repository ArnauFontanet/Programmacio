#include <stdio.h>
#include <math.h>
void operacio(int n1, int n2, char oper, float* resul, int* error);
int main()
{

    int num1, num2;
    char op;
    float resultat = 0;
    int errorr = 0;
    printf("Introdueix el primer nombre: \n");
    scanf_s("%d", &num1);
    printf("Introdueix el segon nombre: \n");
    scanf_s("%d", &num2);
    printf("MENU\n+ --> Suma\n- --> Resta\n* --> Multiplicar\n/ --> Dividir\n^ --> Potencia\ns --> Sortir\nTria una opcio:\n");
    scanf_s(" %c", &op, 1);
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

    default:
        *error = -1;
        break;
    }
}