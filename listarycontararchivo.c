/*
Leer un archivo y contar las palabras del mismo, y cuantas veces aparecen.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LNOM 50

struct palabras {
	char palabra[LNOM];
	int cont;
	struct palabras *pSig;
};

typedef struct palabras nodo, *pNodo;

int main() {
	char cad[LNOM];
	char i, c;

	FILE *pf;
	pNodo inicio = NULL,pNuevo;

	pf = fopen("palabras.txt", "rt");

	if (!pf) {
		printf("Error abriendo archivo.");
			return -1;
	} else {
		pNuevo = (pNodo)malloc(sizeof(nodo));
		if (pNuevo == NULL) {
			printf("Error de memoria.");
			return -1;
		}
		else {

		}
		fscanf(pf, "%s", cad);
		while (!feof(pf)){
		strcpy(pNuevo->palabra, cad);
		pNuevo->cont++;
		printf("%d %s\n", pNuevo->cont,cad);
			
				fscanf(pf, "%s", cad);
				strcpy(pNuevo->palabra, cad);
			}
		}
	fclose(pf);
	printf("\n");
	return 0;
}