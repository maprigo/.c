#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int diasMes(int m, int a);

int menu (int *);

int main(void)
{
	int opc;
	menu(&opc);
	printf("%d\n",opc);
	return 0;
}

int menu(int * opc)
{
	
	printf("1.\"Calcular Multiplo\"\n 0.\"Salir\"\n");
	printf("Ingrese la Opcion deseada\n");
	scanf("%d\n",&opc);
	return *opc;
}


