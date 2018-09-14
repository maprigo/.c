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
void pasarMayuscula(char c[]);
pnodo estaEnLista(pnodo ini,char busq[]);
pnodo agregraALista(pnodo ini,pnodo nuevo);
void Listar(pnodo ini);
pnodo liberar(pnodo ini);

int main(void)
{
	pnodo inicio = NULL, nuevo, actual,esta;
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
				pasarMayuscula(nombre);
			}
			esta=estaEnLista(inicio,nombre);
			if (esta!=NULL)
			{
				//printf("Esta en la lista, la palabra:%s\n",nombre);
				esta->cont++;
			}
			else
			{
				printf("No esta en la lista, la palabra:%s\n",nombre);
				nuevo=(pnodo)malloc(sizeof(nodo));
				strcpy(nuevo->nombre,nombre);
				nuevo->cont=1;
				inicio=agregraALista(inicio,nuevo);
			}
			if(EsSeparador(c))
			{
				i = 0;
			}
			c = fgetc(pf);
		}
	}
	Listar(inicio);
	inicio=liberar(inicio);
	Listar(inicio);
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

void pasarMayuscula(char c[])
{
	
	for (int i = 0; i < strlen(c); ++i)
	{
		c[i]=toupper(c[i]);
	}
}
pnodo estaEnLista(pnodo ini,char busq[])
{
    while(ini !=NULL && strcmp(ini->nombre,busq)!=0)
    {
        ini=ini->psig;
    }
    return ini;
}
pnodo agregraALista(pnodo ini,pnodo nuevo)
{
	nuevo->psig=ini;
	ini=nuevo;

	return ini;
}
void Listar(pnodo ini)
{	

	while(ini!=NULL)
	{
		printf("la palabra:%s aparece:%d\n",ini->nombre,ini->cont);
		ini=ini->psig;
	}
	if(ini==NULL)
	{
		printf("no hay nada que listar\n");
	}
	

}
pnodo liberar(pnodo ini)
{	
	pnodo aux;
	while(ini!=NULL)
	{	
		aux=ini;
		printf("la palabra se libero:%s aparece:%d\n",ini->nombre,ini->cont);
		free(ini);
		ini=aux->psig;
	}
	return ini;

}