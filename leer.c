#define _CRT_SECURE_NO_WARNINGS
#define LNOM 100

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct n
{
	char nombre[LNOM];
	struct n *psig;
	int cont;
};

typedef struct n nodo;
typedef nodo *pnodo;

void ingresarcadena(char v[], int tam, char mensaje[]);
int EsSeparador(char c);
void convertMay(char palabra[]);

int main(void)
{
	pnodo inicio = NULL, nuevo, liberar, actual;
	FILE *pf;
	int  i = 0, enPalabra = 0;
	nodo nombrelista;
	char nombre[LNOM], nombrearchivo[LNOM], c;
	printf("Ingresar archivo\n");
	scanf("%s", nombrearchivo);
	if (strchr(nombrearchivo, '\n'))
	{
		*strchr(nombrearchivo, '\n') = '\0';
	}
	pf = fopen(nombrearchivo, "rt");
	if (pf == NULL)
	{
		printf("No se puede leer el archivo\n");
		return 1;
	}
	else
	{
		c=fgetc(pf);
		while (!feof(pf))
		{
			if (!EsSeparador(c))
			{
				while (!EsSeparador(c))
				{
					nombre[i] = c;
					i++;
					c = fgetc(pf);
				}
				nombre[i] = '\0';
				printf("%s\n", nombre);
			}

			if (EsSeparador(c))
			{
				i = 0;
			}
			c = fgetc(pf);
		}
	}
	system("pause");
	return 0;
}

int EsSeparador(char c)
{
	static char s[] = { " ,.;:-+_@?!/*\'\"$#\n" };
	if (strchr(s, c))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}