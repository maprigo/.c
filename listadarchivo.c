#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

#define LNOM 32
#define ARCH "palabras.txt"

struct n {
	char nombre[LNOM];
	int cont;
	struct n * psig;
};

typedef struct n nodo;
typedef nodo *pnodo;
int EsSeparador( char c);
int main (void)
{
	char c,cad[LNOM];
	int i=0;
	FILE *pf=fopen(ARCH,"rt");
	pnodo inicio=NULL,actual,liberar,nuevo;
	//nuevo=(pnodo)malloc(sizeof(nodo));//esto es para pasar todo lo que leamos , te deja el nuevo apuntando a la estructura.

	if(pf!=NULL)
	{
		c=(char)fgetc(pf);
		while(!EsSeparador(c))
		{
			cad[i]=c;
			i++;	
		}
		cad[i]='\0';
		printf("%s\n",cad);
	}
	else
	{
		printf("no se pudo abrir: %s\n",ARCH);
	}


	//printf("hola\n");
	return 0;

}

int EsSeparador( char c)
{
	static char separadores[] = " ,.-+*/#&=;:_\"\'?!()[]{}\n";
	if (strchr(separadores, c))
		return 1;
	return 0;
}