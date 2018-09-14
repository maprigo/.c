#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void cargarVector(int pv[],int cant); //prototipo
//void ordenar(int [],int);
void mostrar(int[],int);

//prototipo
int main(void)
{
  //boligatorio decir a que tipo de datos apuntamos
    int *pv,cant; //*pv es un puntero a 
    printf("Ingresar cantidad de elementos: ");
    srand((unsigned int )time(NULL));
    scanf("%d",&cant);
    pv=(int *) malloc(cant*sizeof(int)); //cast del puntero. 
    if(pv!=NULL)
    {
        //printf("%p\n",pv);
        cargarVector(pv,cant);
        mostrar(pv,cant);
        ordenar(pv,cant);
        //mostrar();
        free(pv);
    }
    else
    {
        printf("Insuf memoria\n");
    }
    return 0;
  }

  void cargarVector(int pv[],int cant)
  {
    for (int i = 0; i < cant; ++i)
    {
         pv[i]=rand()%10;
    }
  }
  void mostrar(int pv[],int cant)
  {
    for (int i = 0; i < cant; ++i)
    {
         printf("posicion[%d]:%d\n",i, pv[i]); 
    }
  }