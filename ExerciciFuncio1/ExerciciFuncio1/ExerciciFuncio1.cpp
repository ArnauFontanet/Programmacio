#include <stdio.h>
#include <string.h>
void Exercici1();
void Par(int num, int vegada);

void Exercici2();
float media2(float num1, float num2);

void Exercici3();
void media3(float num1, float num2, float num3);

void Exercici4();
void saludo();

void Exercici5();
int negativo(int num, int vegada);

void Exercici6();
float suma(float num1, float num2);
float resta(float num1, float num2);
float multiplicacio(float num1, float num2);
float divisio(float num1, float num2);

int main()
{
    //Exercici1();
    //Exercici2();
    //Exercici3();
    //Exercici4();
    //Exercici5();
    Exercici6();
}

//EXERCICI 1
void Exercici1() {
    int vegades;
    int num;
    printf("\nIndica quants cops vols fer la funcio: ");
    scanf_s("%d", &vegades);
    for(int i = 1; i <= vegades; i++) {
        printf("\nIntrodueix un numero: ");
        scanf_s("%d", &num);
        Par(num, i);
    }
   
}
void Par(int num, int vegada) {
    if (num % 2 == 0) {
        printf("%d. Par (1)\n", vegada);
    }
    else {
        printf("%d. Impar (0)\n", vegada);
    }
}


//EXERCICI 2
void Exercici2() {
    float num1, num2;
    printf("\nIntrodueix el primer nombre: ");
    scanf_s("%f", &num1);
    printf("\nIntrodueix el segon nombre: ");
    scanf_s("%f", &num2);
    float mitja = media2(num1, num2);
    printf("La mitja es: %f", mitja);
    
}
float media2(float num1, float num2) {
    float mitja;
    mitja = (float(num1) + float(num2)) / 2;
    return mitja;
}


//EXERCICI 3
void Exercici3() {
    float num1, num2, num3;
    printf("\nIntrodueix el primer nombre: ");
    scanf_s("%f", &num1);
    printf("\nIntrodueix el segon nombre: ");
    scanf_s("%f", &num2);
    printf("\nIntrodueix el tercer nombre: ");
    scanf_s("%f", &num3);
    media3(num1, num2, num3);
}
void media3(float num1, float num2, float num3) {
    float mitja;
    mitja = (num1 + num2 + num3) / 3;
    printf("\nLa mitja es: %f", mitja);
}


//EXERCICI 4
void Exercici4() {
    saludo();
}
void saludo() {
    printf("Hola");
}

//EXERCICI 5
void Exercici5() {
    int num;
    int vegades;
    printf("\nIntrodueix quants cops vols fer la funcio: ");
    scanf_s("%d", &vegades);
    for (int i = 1; i <= vegades; i++) {
        printf("\n\nIntrodueix un nombre enter: ");
        scanf_s("%d", &num);
        negativo(num, i);
        if (negativo(num, i) == 0) {
            printf("Positiu");
        }
        else {
            printf("Negatiu");
        }
    }
    
}
int negativo(int num, int vegada) {
    if (num < 0) {
        return 1;
    }
    else {
        return 0;
    }
}

//EXERCICI 6
void Exercici6() {
    bool continuar = true;
    char sino[3];
    do {
        int be = 1;
        float num1, num2;
        printf("\nIntrodueix el primer nombre: ");
        scanf_s("%f", &num1);
        printf("\nIntrodueix el segon nombre: ");
        scanf_s("%f", &num2);
        float sumaa = suma(num1, num2);
        float restaa = resta(num1, num2);
        float mult = multiplicacio(num1, num2);
        float divi = divisio(num1, num2);
        printf("\nSuma: %f \nResta: %f \nMultiplicacio: %f \nDivisio: %f", sumaa, restaa, mult, divi);
        printf("\n\nVols introduir nous nombres?\n(si / no)\n");
        ////netejar buffer per al gets_s sino detecta el \n i para de llegir la linea i no funciona
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        //fi neteja
        do {
            
            gets_s(sino, 3);
            if (sino[0] == 's' && sino[1] == 'i') {
                continuar = true;
                be = 1;
            }
            else if (sino[0] == 'n' && sino[1] == 'o') {
                continuar = false;
                be = 1;
            }
            else {
                be = 0;
            }
        } while (be == 0);
        

    }
    
    while (continuar == true);
}
float suma(float num1, float num2) {
    float resultat = num1 + num2;
    return resultat;
}
float resta(float num1, float num2) {
    float resultat = num1 - num2;
    return resultat;
}
float multiplicacio(float num1, float num2) {
    float resultat = num1 * num2;
    return resultat;
}
float divisio(float num1, float num2) {
    float resultat = num1 / num2;
    return resultat;
}