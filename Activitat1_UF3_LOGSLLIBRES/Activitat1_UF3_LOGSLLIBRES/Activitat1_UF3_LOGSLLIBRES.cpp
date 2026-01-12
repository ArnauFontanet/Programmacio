#include <stdio.h>
#include <stdlib.h>


void registrarPrestec();
void registrarRetorn();
void llistarPendents();
int comprovarSiTornat(int idBuscat);

int main() {
    int opcio = 0;

    do {
        printf("1. Prestar llibre\n2. Tornar llibre\n3. Veure llibres no tornats\n4. Sortir\nEscull una opcio: ");
        scanf_s("%d", &opcio);
        switch (opcio) {
        case 1:
            registrarPrestec();
            break;
        case 2:
            registrarRetorn();
            break;
        case 3:
            llistarPendents();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Opcio incorrecta.\n");
        }
    } while (opcio != 4);

    return 0;
}

void registrarPrestec() {
    FILE* f;
    int id;
    char isbn[50];
    char titol[50];
    char autor[50];

    printf("\nIntrodueix ID (unic): ");
    scanf_s("%d", &id);
    printf("Introdueix ISBN: ");
    scanf_s("%s", isbn, (unsigned)50);
    printf("Titol (usa_guions_baixos): ");
    scanf_s("%s", titol, (unsigned)50);
    printf("Autor (usa_guions_baixos): ");
    scanf_s("%s", autor, (unsigned)50);
    errno_t err = fopen_s(&f, "prestecs.txt", "a");
    if (err == 0) {
        fprintf(f, "%d %s %s %s\n", id, isbn, titol, autor);
        fclose(f);
        printf("Llibre registrat correctament\n");
    }
    else {
        printf("Error al obrir el fitxer prestecs\n");
    }
}

void registrarRetorn() {
    FILE* f;
    int id;
    printf("\nIntrodueix la ID del llibre que vols tornar: ");
    scanf_s("%d", &id);
    errno_t err = fopen_s(&f, "retorns.txt", "a");
    if (err == 0) {
        fprintf(f, "%d\n", id);
        fclose(f);
        printf("Retorn registrat correctament\n");
    }
    else {
        printf("Error al obrir el fitxer de retorns\n");
    }
}

void llistarPendents() {
    FILE* f_prestecs;

    int id_llegida;
    char isbn[50], titol[50], autor[50];
    int hi_ha_pendents = 0;

    errno_t err = fopen_s(&f_prestecs, "prestecs.txt", "r");

    if (err != 0) {
        printf("Encara no s'ha prestat cap llibre (fitxer no existeix).\n");
        return;
    }

    printf("\nLlibres pendents de tornar:\n");

    while (fscanf_s(f_prestecs, "%d %s %s %s",
        &id_llegida,
        isbn, (unsigned)50,
        titol, (unsigned)50,
        autor, (unsigned)50) == 4) {

        int esTornat = comprovarSiTornat(id_llegida);

        if (esTornat == 0) {
            printf("ID: %d | Titol: %s | Autor: %s\n", id_llegida, titol, autor);
            hi_ha_pendents = 1;
        }
    }

    if (hi_ha_pendents == 0) {
        printf("No hi ha llibres pendents de tornar\n\n");
    }

    fclose(f_prestecs);
}

int comprovarSiTornat(int idBuscat) {
    FILE* f_retorns;
    int id_retornada;
    int trobat = 0;

    errno_t err = fopen_s(&f_retorns, "retorns.txt", "r");

    if (err != 0) return 0;

    while (fscanf_s(f_retorns, "%d", &id_retornada) == 1) {
        if (id_retornada == idBuscat) {
            trobat = 1;
            break;
        }
    }

    fclose(f_retorns);
    return trobat;
}