//Ingresar nombres y almacenarlos asi como vienen (desordenados)
#define _CRT_SECURE_NO_WARNINGS
#define LNOM 32
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//siempre la estructura va antes que las funciones
struct n
{
	char nombre[LNOM];
	struct n * psig; //apunta al próximo nodo
}; 
typedef struct n nodo;
typedef nodo *pnodo; //puntero a nodo (estructura)
pnodo insertarordenado(pnodo inicio, pnodo nuevo) ;
int ingresarCadena(char cad[],int tam,char mensaje[]);

int main(void)
{
	char nombre[LNOM]; //VARIABLE (cadena de caracteres) AUXILIAR NOMBRE - temporal, donde guardo el nombre para meter en el nodo
	pnodo inicio = NULL, nuevo, liberar, actual; // inicio es un puntero al primer nodo de la lista, lo inicializo con NULL por que la lista esta vacia. Variable nuevo del tipo pnodo que es la que usamos cuando fabricamos nuevos nodos. Pedir memoria a malloc para eso.
	ingresarCadena(nombre, LNOM, "texto a guardar (nombre del nodo)"); //me permite ingresar algo y guardarlo en nombre
	while ((int)strlen(nombre) > 0) // Mientras la longitud de lo que tiene nombre sea mayor a cero, si no ponemos nombre, la longitud queda en cero.
	{
		//printf("%d\n",(int)strlen(nombre));
		nuevo = (pnodo)malloc(sizeof(nodo));
		if (nuevo == NULL) //Verifico que me den memoria
		{
			printf("No hay memoria\n");
			nombre[0] = '\0';
		}
		else
		{
			strcpy(nuevo->nombre, nombre);//copio en nuevo, el nombre que tengo. Me lo pone en el miembro nombre de la estructura.
			
			nuevo->psig = inicio; //le flecha nos permite acceder directamente a la estructura. Lo que yo tenia en la lista lo pongo atras de nuevo (atras es igual al puntero que salde delante del nodo)
			
			inicio 	= nuevo;// Pido otro nombre, recordar que Nuevo lo usamos temporalmente y no puede hacer un free,  desde que pido memoria a MALLOC, cuando le doy a inicio lo de nuevo (concatenar el nodo con la lista) no necesito más nuevo. Copio lo de nuevo a Inicio.
			
			ingresarCadena(nombre, LNOM, "Nombre que quiero para el nodo"); // uso esto para volver a ingresar un nuevo nombre de haberlo, si lo hay vuelvo a entrar al While
			
		}
	}
	actual = inicio; //lo copio como temporal para no perderlo
	while (actual != NULL) //mientras inicio no sea NULL y vamos a MOSTRAR LO QUE HAY EN EL NODO
	{
		printf("ingreso a 1\n");
		printf("%s\n", actual->nombre); //muestro y vacio la lista simultaneamente (muestro y vacio)
		actual = actual->psig; //es para avanzar en el nodo, todo esto es para mostrar y AVANZAR en el nodo
		printf("ingreso a liberar\n");
	}
	printf("ingreso a liberar\n");
	while (inicio != NULL) //aca vamos a LIBERAR LA LISTA
	{
		liberar = inicio; // me guardo una copia de inicio antes de avnazar al proximo
		inicio = inicio->psig; // me muevo al próximo (es decir, si el primero es Ana, pasa a mirara Pedro que es el que le sigue)
		free(liberar); //libero memoria de liberar al sistema
	}
	//system("pause");
	return 0;
}

//esta función me permite ordenar los nodos al ingresarlo iria en el main luego del strcpy, SE LLAMA ASI: INICIO = INSERTARORDENADO(INICIO,NUEVO)

pnodo insertarordenado(pnodo inicio, pnodo nuevo) //cuando ya tenemos el nuevo nodo y lo vamos a agregar a la lista usamos esto
{
	//llamamos a esta función luego de darle a memoria el nombre (osea ya pedi la memoria) Le paso a esta función el inicio de la lista y donde esta el nuevo nodo, AMBOS PUNTEROS
	pnodo actual, anterior;
	if (inicio == NULL) //me fijo si la lista esta vacia, si es verdad la LISTA ESTABA VACIA entonces tenemos que darle a NUEVO->psig el valor de NULL, ESTA SOLO ASI QUE NO SIGUE A NADIE
	{
		nuevo->psig = NULL;
		inicio = nuevo;
		return inicio; //CUANDO ESTO VUELVA, LE DEVUELVE AL QUE LLAMO EL INICIO
	}
	if (strcmp(nuevo->nombre, inicio->nombre) < 0) //insertar al inicio
	{
		nuevo->psig = inicio;
		inicio = nuevo;
		return inicio;
	}
	anterior = NULL;
	actual = inicio;
	while (actual != NULL && strcmp(actual->nombre, nuevo->nombre) <= 0)
	{
		anterior = actual;
		actual = actual->psig;
	}
	if (actual == NULL)
	{
		nuevo->psig = NULL;
		anterior->psig = nuevo;
	}
	else
	{
		nuevo->psig = actual;
		anterior->psig = nuevo;
	}
	{
		nuevo->psig = actual;
		anterior->psig = nuevo;
	}
	return inicio;
}
int ingresarCadena(char cad[],int tam,char mensaje[])
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