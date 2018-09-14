//manejo de cadenas
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define TAM 10

int ingresarcad(char cad[],int	tam,char mensaje[]);
void mostrarcad(char cad[]);
int capicua(char cad[]);
int encontrarespacio(char cad[]);
void sespacio(char cad[]);



int main (void)
{	
	char cad[TAM];
	char mensaje[]="Ingrese la cadena please\n";


	ingresarcad(cad,TAM,mensaje); // cuando paso el vector va solo el nombre del vector
	//mostrarcad(cad);
	sespacio(cad);
	mostrarcad(cad);
	/*if (capicua(cad))
		printf("es capicua\n");
	else
		printf("no es capicua\n");
	//printf("%d:\n",ingresarcad(cad,TAM,mensaje));
	*/
	return 0;
}

int ingresarcad(char cad[],int tam,char mensaje[])
{
	int i;
	printf("%s",mensaje );
	fgets (cad,tam,stdin);
	i=0;
	while (cad[i]!='\n'&& cad[i] !='\0')
	i++;
	if (cad[i]=='\0')
		while(fgetc(stdin)!='\n');
	else
		cad[i]='\0';
	return i;
}
void mostrarcad(char cad[])
{
	printf("%s\n",cad);
}
int capicua(char cad[])
{
	int a,es,i;
	a=strlen(cad);
	for (i = 0; i <= a/2; ++i)
	{
		if (cad[i]==cad[a-1])
		{
			es=1;
		}
		else 
		{
			es=0;
		}
	a--;
	}
	return es;
}
void sespacio(char cad[])
{
	int a,aux,pos,j,i;
	a=strlen(cad);
	for (i = 0; i < a; ++i)
	{
		if (encontrarespacio(cad)!=-1)
		{
			pos=encontrarespacio(cad);
			//printf("%d\n",encontrarespacio(cad));
			for ( j = pos; j <=a; ++j)
			{
				//printf("hola1\n");
				cad[j]=cad[j+1];				
			}
		a=strlen(cad);
		}
	}


}
int encontrarespacio(char cad[])
{

	int a=-1,b,i;
	b=strlen(cad);
	for (i = 0; i<b; ++i)
	{
		if (cad[i]==' ')
		{
			//printf("pos del espacio:%d\n", i);
			a=i;
		}
	}
	return a;


}
