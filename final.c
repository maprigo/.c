#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define LPAT 10
#define LLOC 100
struct n{
	char patente[LPAT];
	int horauno,minuno,horados,mindos;
	char localidad[LLOC];
	int nlocal;
	struct n *psig;
};
typedef struct n nodo;
typedef nodo *pnodo;
pnodo armarlista(pnodo inicio, pnodo nuevo);
pnodo abrirArch(pnodo inicio ,pnodo nuevo);
void listar(pnodo inicio);
pnodo Buscar(pnodo inicio,char patente[]);

int main (void)
{
	pnodo inicio=NULL,nuevo=NULL;
	
	inicio=abrirArch(inicio,nuevo);
	listar(inicio);
	return 0;
}

pnodo abrirArch(pnodo inicio ,pnodo nuevo)
{
	FILE *pf=fopen("patente.txt","rt");
	pnodo esta;
	  char pat[LPAT+1];
	  if(pf==NULL)
	  {
	    printf("No se puede abrir el archivo \n");
	    return 0;//return cant;
	  }
	  fgets(pat,LPAT,pf);
	  while(!feof(pf))
	  {
	  	nuevo=(pnodo)malloc(sizeof(nodo));
	    *strchr(pat,'\n')='\0';
	    esta=Buscar(inicio,pat);
	    if (esta)
	    {	
	    	strcpy(esta->patente,pat);
		    fscanf(pf,"%d:%d",&esta->horados,&esta->mindos);
		    fgetc(pf);
		    fgets(esta->localidad,LLOC,pf);
		    fscanf(pf,"%d",&esta->nlocal);
		    fgetc(pf);
	    }else
	    {
	    	strcpy(nuevo->patente,pat);
		    fscanf(pf,"%d:%d",&nuevo->horauno,&nuevo->minuno);
		    fgetc(pf);
		    fgets(nuevo->localidad,LLOC,pf);
		    fscanf(pf,"%d",&nuevo->nlocal);
		    fgetc(pf);
		    inicio=armarlista(inicio,nuevo);
	    }
	    
	    
	    fgets(pat,LPAT,pf);
	  }
	  fclose(pf);
	  return inicio;
}
pnodo armarlista(pnodo inicio, pnodo nuevo)
{
	nuevo->psig=inicio;
	inicio=nuevo;	
	return inicio;
}
void listar(pnodo inicio){

	while(inicio!=NULL)
	{
		printf("patente: %s\n",inicio->patente);
		printf("hora uno %d:%d: \n",inicio->horauno,inicio->minuno);
		printf("hora uno %d:%d: \n",inicio->horados,inicio->mindos);
		inicio=inicio->psig;
	}

}
pnodo Buscar(pnodo inicio,char patente [])
{
	while(inicio!=NULL && strcmp(inicio->patente,patente)!=0)
	{
		inicio=inicio->psig;
	}
	return inicio;
}