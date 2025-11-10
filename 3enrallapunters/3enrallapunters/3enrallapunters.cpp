#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mostrarMapa(char mapa[3][3]);
void posicioMaquina(int pos[2], char mapa[3][3]);
void posicioJugador(int pos[2], char mapa[3][3]);
int acabarMaquina(char mapa[3][3], int acabarJocMaquina);
int acabarJugador(char mapa[3][3], int acabarJocJugador);
int restants(int intents);
int main()
{
	srand(time(NULL));
	char mapa[3][3];
	int posJugador[2];
	int posMaquina[2];
	int acabarJocMaquina = 0;
	int acabarJocJugador = 0;
	int intents = 9;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mapa[i][j] = '-';
		}
	}
	mostrarMapa(mapa);
	do
	{
		intents = restants(intents);
		posicioMaquina(posMaquina, mapa);
		mostrarMapa(mapa);
		acabarJocMaquina = acabarMaquina(mapa, acabarJocMaquina);
		if (intents >= 1) {
			posicioJugador(posJugador, mapa);
			intents = restants(intents);
			mostrarMapa(mapa);
			acabarJocJugador = acabarJugador(mapa, acabarJocJugador);
		}
	} while ((acabarJocMaquina == 0 && acabarJocJugador == 0) && intents > 0);
	if (acabarJocJugador == 1){
		printf("Has guanyat!\n");}
	else if (acabarJocMaquina == 1){
		printf("Has perdut!\n");}
	else{
		printf("Empat!\n");}
}
void mostrarMapa(char mapa[3][3]) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c ", mapa[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
void posicioMaquina(int pos[2], char mapa[3][3]) {
	do
	{
		for (int i = 0; i < 2; i++)
		{
			pos[i] = rand() % 3;
		}
	} while (mapa[pos[0]][pos[1]] != '-');
	mapa[pos[0]][pos[1]] = 'O';
}
void posicioJugador(int pos[2], char mapa[3][3]) {
	do
	{
		for (int i = 0; i < 2; i++)
		{
			scanf_s("%d", &pos[i]);
		}
	} while (mapa[pos[0]][pos[1]] != '-');
	mapa[pos[0]][pos[1]] = 'X';
}
int acabarMaquina(char mapa[3][3], int acabarJocMaquina) {
	for (int i = 0; i < 3; i++){
		if (mapa[i][0] == 'O' && mapa[i][1] == 'O' && mapa[i][2] == 'O'){
			acabarJocMaquina = 1;}
		else if (mapa[0][i] == 'O' && mapa[1][i] == 'O' && mapa[2][i] == 'O') {
			acabarJocMaquina = 1;}}
	if (mapa[0][0] == 'O' && mapa[1][1] == 'O' && mapa[2][2] == 'O'){
		acabarJocMaquina = 1;}
	else if (mapa[2][0] == 'O' && mapa[1][1] == 'O' && mapa[0][2] == 'O'){
		acabarJocMaquina = 1;}
	return acabarJocMaquina;
}
int acabarJugador(char mapa[3][3], int acabarJocJugador) {
	for (int i = 0; i < 3; i++) {
		if (mapa[i][0] == 'X' && mapa[i][1] == 'X' && mapa[i][2] == 'X') {
			acabarJocJugador = 1;}
		else if (mapa[0][i] == 'X' && mapa[1][i] == 'X' && mapa[2][i] == 'X') {
			acabarJocJugador = 1;}}
	if (mapa[0][0] == 'X' && mapa[1][1] == 'X' && mapa[2][2] == 'X') {
		acabarJocJugador = 1;}
	else if (mapa[2][0] == 'X' && mapa[1][1] == 'X' && mapa[0][2] == 'X') {
		acabarJocJugador = 1;}
	return acabarJocJugador;
}
int restants(int intents) {
	intents--;
	printf("Caselles restants: %d\n\n", intents);
	return intents;
}