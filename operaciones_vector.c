/* operaciones con vector */
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void cargar(int[]);
void mostrar(int[]);

int main(void)
{
	int v[TAM];
	cargar (v);
	mostrar(v);
	return 0;
}
void cargar(int v []){
	int i;
	for (int i = 0; i < TAM; ++i)
	{
		printf("[%d]:",i+1 );
		scanf("%d",&v[i]);

	}
}

void mostrar(int v [])
{
	int i;
	for (int i = 0; i < TAM; ++i)
	{
		printf("%4d",v[i]);
		printf("\n");

	}
}
