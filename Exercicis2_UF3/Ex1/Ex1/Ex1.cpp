#include <stdio.h>
FILE* f;
void limpiarArray(int a[4][3]);
void imprimirArray(int a[4][3]);
int rellenarArray(int a[4][3], int* n);
int main()
{
    int v[4][3];
    int nums = 0;
    printf("limpiarArray:\n");
    limpiarArray(v);
    printf("Fi\nimprimirArray:\n");
    imprimirArray(v);
    printf("fi\nrellenarArray:\n");
    rellenarArray(v, &nums);
    printf("fi\n");
    return 0;
}

void limpiarArray(int a[4][3]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = 0;
        }
    }
}
void imprimirArray(int a[4][3]) {
    printf("\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}
int rellenarArray(int a[4][3], int* n) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("\nIntrodueix un valor: ");
            scanf_s("%d", &a[i][j]);
            if (a[i][j] <= 5) {
                *n += 1;
            }
        }
    }
    errno_t err = fopen_s(&f, "nums5.txt", "w+");
    if (err) {
        printf("Error al obrir el fitxer.\n");
    }
    else {
        fprintf(f, "Nums menors o iguals a 5: %d\n", *n);
        fclose(f);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    printf("Nums menors o iguals a 5: %d\n", *n);
    return *n;
    
}
