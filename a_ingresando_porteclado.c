//Contar palabras de un archivo ingresando el nombre del archivo por teclado

#define _CRT_SECURE_NO_WARNINGS
#define LEER_ARCHIVO "axteclado.txt"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
//#define LEER_ARCHIVO "Origen.txt" //Agregado para que funcione con archivos
typedef enum { FALSO, VERDAD } bool; //creamos el booleano donde typedef enum designa 0 para el primer valor y 1 para el segundo, 3 para el tercero y así sucesivamente
//en este caso para que FALSO sea 0 y VERDADERO 1 se coloca primero FALSO y después VERDADERO

bool EsSeparador(char); //Prototipo para EsSeparador

int main(void)//Inicio función main **********
{
	bool EnPalabra = FALSO; //Inicializamos en Palabran en FALSO que gracias a lo que hicimos al principio es equivalente a 0
	FILE * pf; //Agregado para que funcione con archivos
	int cantPal = 0, i = 0;
	char c, nombrearchivo[100], palabras[100]; //Inicio Agregado para que funcione con archivos
	printf("Ingresar Archivo a contar: ");
	scanf("%s", nombrearchivo);
	pf = fopen(nombrearchivo, "rt");
	if (pf == NULL)
	{
		printf("No se puede abrir el archivo \n");
		return 1;
	}

	//while((c=fgetc(pf)) != EOF)
	c = fgetc(pf); //trae la dirección de memoria
	while (!feof(pf))
	{  //Fin Agregado para que funcione con archivos. Preguntar si el EOF está bien usado/es una buena practica
	//	if (!EnPalabra) //Hacer esto cuando EnPalabra sea FALSO es decir si no está en palabra hay que hacer buscar si el caracter es un separador
		{
			if (!EsSeparador(c))/* inicio palabra - Entramos en la supuesta palabra, utilizando la función EsSeparador vemos si el caracter es un separador */
			{
				EnPalabra = VERDAD; // en caso que lo sea, aplicamos VERDAD
				cantPal++; //Incrementamos el contador de palabras
				while (!EsSeparador(c))
				{
					palabras[i] = c; // guardo en mi string cada caracter HASTA QUE FORME UNA PALABRA, el puntero
					i++;
					c = fgetc(pf);
				}
				palabras[i] = '\0';
				printf("%s\n", palabras);
			}
		}
		//else
		{
			if (EsSeparador(c)) /* fin palabra - Volvemos a usar EsSeparador para verificar que lo que tenemos como caracter sea un separador */
			{
				EnPalabra = FALSO;  //Asignamos un FALSO y volvemos a empezar
				i = 0;
			}
		}
		c = fgetc(pf);
	}
	printf("Cantidad de palabras: %d\n", cantPal);  //mostramos la magia de cuantas palabras obtenemos
	fclose(pf);
	system("pause");
	return 0; //Importante. debe devolver algo porque main tiene un int en la declaración
} //Fin función main ****************

bool EsSeparador(char c)  //Inicio funcion EsSeparador, con un char de nombre c que se recibe como parámetro
{
	static char separadores[] = " ,.-+*/#&=;:_\"\'?!()[]{}\n";  //Inicializamos un vector que tiene como contenido todos los separadores posibles
	if (strchr(separadores, c))  //haciendonos de la función strchr buscamos en el vector separadores el caracter recibido como parámetro c
	{
		return VERDAD; //si lo encontramos es decir que strchr devuelve un 1 por ser TRUE devolvemos un VERDADERO
	}
	return FALSO; //si no se cumple devolvemos un falso, esto tambien podría ser un else, pero no es necesario.
}