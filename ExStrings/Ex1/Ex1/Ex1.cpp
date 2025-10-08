#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char text[100];
	int contador = 0;
	printf("Escriu el text de no mes de 100 caracters: \n");
	gets_s(text);
	for (int i = 0; i < 100; i++) {
		if (text[i] == 'l') {
			if (text[i + 1] == 'a') {
				contador += 1;
			}
		}
	}
	printf("\nEl text introduit conte %d cops la silaba 'la': ", contador);
	return 0;
}
