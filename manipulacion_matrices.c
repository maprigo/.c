//manipulacion de matrices 
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUP 99
#define FIL 4
#define INF 10
#define COL 4 

void cargar(int matriz [FIL][COL]);
void mostrar(int matriz [FIL][COL]);
void ordenar(int matriz [FIL][COL]);
void intercalar(int matriz [FIL][COL]);

int main(void)
{
	int matriz[FIL][COL]={{0}};
	srand((unsigned int) time(NULL) );
	//cargar(matriz);
	mostrar(matriz);
	//ordenar(matriz);
	//intercalar(matriz);
	mostrar(matriz);
	return 0;
}

void cargar (int matriz [FIL][COL])
{
	int f,c;
	for(f=0;f<FIL;f++)
		for (c=0;c<COL; c++)
		{
			matriz[f][c]=rand()%(SUP-INF+1)+INF;
		}
}
void mostrar (int matriz[FIL][COL])
{
	int f,c;
	for(f=0;f<FIL;f++)
	{
		for (c=0;c<COL; c++)
			printf("%4d",matriz[f][c]);
		printf("\n");
	}
printf("\n");
}
void ordenar (int matriz[FIL][COL])
{
	int f=0,c=0,ordenado=0, aux;
	while (!ordenado)
	{
		ordenado=1;

		for (c = 0; c< COL-1; c++)
		{
			if (matriz[0][c] > matriz[0][c+1])
			{
				for(f=0;f<FIL;f++)
				{
					aux=matriz[f][c];
					matriz[f][c]=matriz[f][c+1];
					matriz[f][c+1]=aux;
				}
			ordenado=0;
			}
		}
	}
}
void intercalar (int matriz[FIL][COL])
{
	int f,c=0,aux,colu;
	colu=COL;
	for (f = 0; f < FIL; f++)
	{
		aux=matriz[f][c];
		matriz[f][c]=matriz[f][colu];
		matriz[f][colu]=aux;
		c++;colu--;
	}
}


