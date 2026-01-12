#include <stdio.h>
#include <stdlib.h>
#include <time.h>
FILE* f;
void numMaquina(int *n);
void numJugador(int* n);
void guanyador(int *wM, int* wJ, int *m, int *j);
int main()
{
    srand(time(NULL));
    int numM;
    int numJ = 5;
    int wM = 0;
    int wJ = 0;
    int acabar = 0;
    do {
        numMaquina(&numM);
        numJugador(&numJ);
        guanyador(&wM, &wJ, &numM, &numJ);
        printf("Vols tornar a jugar? 0 = Si  1 = No\n");
        scanf_s("%d", &acabar);
    } while (acabar == 0);
    printf("S'ha acabat el joc.");
    errno_t err2 = fopen_s(&f, "datos.txt", "a");
    if (err2) {
        printf("Error al obrir el fitxer.\n");
    }
    else {
        fprintf(f, "Victories maquina: %d   Victories Jugador: %d", wM, wJ);
    }
    return 0;
}

void numMaquina(int* n) {
    *n = rand() % 2;
}
void numJugador(int* n) {
    do {
        printf("\n\nIntrodueix 0 o 1: ");
        scanf_s("%d", n);
    } while (*n != 0 && *n != 1);
}
void guanyador(int* wM, int* wJ, int* m, int* j) {
    errno_t err = fopen_s(&f, "datos.txt", "a");
    if (err) {
        printf("Error al obrir el fitxer.\n");
    }
    else {
        if (*m == *j) {
            *wJ += 1;
            fprintf_s(f, "Maquina: %d, Jugador: %d.\nGuanyador = Jugador\n", *m, *j);
            fclose(f);
        }
        else {
            *wM += 1;
            fprintf_s(f, "Maquina: %d, Jugador: %d.\nGuanyador = Maquina\n", *m, *j);
            fclose(f);
        }
    }
    
}