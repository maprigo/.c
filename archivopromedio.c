//leer el archivo 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define LNOM 15
#define MAX 10
struct persona{
	char nombre[LNOM];
	int promedio;
};
int leerArchTxt(struct persona alu[]);
void listar (struct persona l[],int n);
int main (void)
{
	int cant;
	struct persona alu[MAX];
	cant=leerArchTxt(alu);
	listar(alu,cant);
	return  0;
}

int leerArchTxt(struct persona alu[])
{
  int cant=0,notas,nota;
  char nom[LNOM+1],digit;//este +1 lo hace por que si se guardo con el enter o salto de linea
  FILE *pf=fopen("lista.txt","rt");
  if(pf==NULL)
  {
    printf("No se puede abrir el archivo \n");
    return 0;//return cant;
  }
  fgets(nom,LNOM,pf);
  while(!feof(pf))
  {
  	alu[cant].promedio=0;
  	notas=0;
    *strchr(nom,'\n')='\0';//esto lo hago por si quiero una vez guardado imprimir todo en una linea
    strcpy(alu[cant].nombre,nom);
    //printf("%d\n",fgetc(pf));
    while(fscanf(pf,"%d",&nota)==1)
    {
    	//printf("%d\n",pf);
    	notas++;
    	alu[cant].promedio=alu[cant].promedio+nota;

    }
    alu[cant].promedio=alu[cant].promedio/notas;
   /* fgets(alu[cant].tel,LTEL,pf);
    *strchr(alu[cant].tel,'\n')='\o';
    fscanf(pf,"%d",&alu[cant].dni);
    fgetc(pf); /* saco enter de arch 
    fscanf(pf,"%d/%d/%d",&alu[cant].nacim.d,&alu[cant].nacim.m,&alu[cant].nacim.a):
    fgetc(pf);//saco enter del archivo*/
    fgets(nom,LNOM+1,pf);
    cant++;
  }
  fclose(pf);
  return cant;
}

void listar (struct persona l[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", l[i].nombre);
		printf("%d\n", l[i].promedio);

	}
}