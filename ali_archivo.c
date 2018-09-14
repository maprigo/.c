//Abrir, leer e imprimir un archivo
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE * pf;//estructura dentro de stdio.h y sirve para trabajar con archivos (FILE). *pf es PUNTERO A FILE.
	int c;
	pf = fopen("Saludos.txt", "rt"); //intenta abrir el archivo (puede fallar por que el archivo no existe, no este en ese dir). Importante fijarse si pf es distinto de NULL
	if (pf != NULL) //Si esto es verdad pude abrir el archivo, yo quiero leerlo e imprimirlo por pantalla
	{
		c = fgetc(pf); //pf es un puntero a FILE y lo guardo en el entero c. Leo un byte del archivo y lo guardo en una variable entero, el número que me devuelve fgetc.
		while (!feof(pf)) //mientras no sea el fin del archivo de pf. Primero leí y luego pregunte por el fin del archivo.
		{
			printf("%c", (char)c); //imprimo por pantalla, ya habiendo leido (para saber que exista el archivo) y luego pregunto mientras no sea el fin del archivo. Casteo (char) por que algunos compiladores no les gusta integer.
			c = fgetc(pf); //vuelvo a leer primero antes de continuar con el próximo carcater.
		}
		fclose(pf); // cierro mi archivo, no puedo acceder el archivo si no lo vuelvo a abrir.
	}
	else
	{
		printf("Hubo error\n"); //Error ya que no existe el archivo.
	}
	system("pause");
	return 0;
}