#include <stdio.h>
int main()
{
    char mapa1[10][10];
    char mapa2[10][10];
    int vidas = 9, intents = 0, atac_fila, atac_columna;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mapa1[i][j] = '-';
            mapa1[i][j] = '-';
        }
    }
    mapa2[0][1] = 'B';
    mapa2[0][2] = 'B';
    mapa2[0][3] = 'B';

    mapa2[2][4] = 'B';
    mapa2[3][3] = 'B';
    mapa2[4][2] = 'B';

    mapa2[7][6] = 'B';
    mapa2[7][7] = 'B';
    mapa2[7][8] = 'B';
        
    while (vidas > 0) {
        printf("Posicions de vaixells restants: %d\n", vidas);
        printf("Mapa actual: \n\n");
        printf("  0 1 2 3 4 5 6 7 8 9\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", i);
            for (int j = 0; j < 10; j++) {
                printf("%c ", mapa1[i][j]);
            }
            printf("\n");
        }
        
        printf("Selecciona la casella a atacar (fila columna): \n");
        scanf_s("%d %d", &atac_fila, &atac_columna);
        if (atac_fila < 0 || atac_fila > 9 || atac_columna < 0 || atac_columna > 9) {
            printf("La casella introduida es incorrecte, ha de ser entre 0 i 9 tant fila com columna. \n");
            continue;
        }
        if (mapa1[atac_fila][atac_columna] != '-') {
            printf("\nJa has atacat aquesta casella, prova amb una altra.\n\n");
            continue;
        }
        if (mapa2[atac_fila][atac_columna] == 'B') {
            printf("\nHas encertat a un vaixell!\n\n");
            mapa1[atac_fila][atac_columna] = 'X';
            vidas--;
        }
        else {
            printf("\nNo has encertat!\n\n");
            mapa1[atac_fila][atac_columna] = 'O';         
        }
        intents++;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
        for (int j = 0; j < 10; j++) {
            printf("%c ", mapa1[i][j]);
        }
        printf("\n");
    }
    printf("\n\nFelictats has guanyat!\n");
    printf("Has necessitat %d intents.\n", intents);
	
}