#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
void atacJugador(int* atacJ);
int atacMaquina();
void guanyador(int jugador, int maquina, int* vic, int* der, int* emp);
void acabarJoc(char *end);
int main()
{
    srand(time(NULL));
    int victories = 0;
    int derrotes = 0;
    int empats = 0;
    char acabar = 'n';
    int accioM;
    int accioJ;
    do {
        accioM = atacMaquina();
        printf("Maquina: %d\n", accioM);
        atacJugador(&accioJ);        
        printf("Jugador: %d\n", accioJ);

        guanyador(accioJ, accioM, &victories, &derrotes, &empats);
        printf("\nVictories: %d\nDerrotes: %d\nEmpats: %d\n", victories, derrotes, empats);
        acabarJoc(&acabar);
    } while (acabar == 'n');
   
}

void atacJugador(int* atacJ) {
    printf("0 - Paper\n1 - Pedra\n2 - Tissores\nIntrodueix l'atac que vols fer: \n");
    scanf_s("%d", atacJ);
}

int atacMaquina() {
    int maquina = rand() % 3;
    return maquina;
}

void guanyador(int jugador, int maquina, int* vic, int* der, int* emp){

    switch(jugador){
    case 0:
        if (maquina == 1) {
            *vic += 1;
        }
        else if (maquina == 2) {
            *der += 1;
        }
        else {
            *emp += 1;
        }
        break;

    case 1:
        if (maquina == 2) {
            *vic += 1;
        }
        else if (maquina == 0) {
            *der += 1;
        }
        else {
            *emp += 1;
        }
        break;

    case 2:
        if (maquina == 0) {
            *vic += 1;
        }
        else if (maquina == 1) {
            *der += 1;
        }
        else {
            *emp += 1;
        }
        break;
    }
}

void acabarJoc(char *end) {
    do {
        printf("Vols acabar la partida? s/n\n");
        scanf_s(" %c", end, 1);
    } while (*end != 'n' && *end != 's');
    
}