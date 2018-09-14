#include <stdio.h>
struct fecha {int d,m,a;};
void cargar(struct fecha *); //prototipo
void mostrar(struct fecha);
void diffecha(struct fecha*r,
               struct fecha f1,
               struct fecha f2);

int main (void)
{
  struct fecha f1,f2,result;
  cargar(&f1);cargar(&f2);
  mostrar(f1);
  mostrar(f2);
  diffecha(&result,f1,f2);
  mostrar(result);
  return 0;
}

void cargar(struct fecha * f) //f es un puntero en la estructura Fecha
{
  do {
    printf("Fecha (d/m/a): ");
    scanf("%d/%d/%d/",&f->d,&f->m,&f->a); //para acceder a una indirección. La alternativa seria hacer (*p).d en vez de f->d
  } while(!esFechaGregoriana(*f));
}

void mostrar(struct fecha f)
{
  prinf("%02d-%02d-%4d\n",f.d,f.m,f.a);
}


int difFecha(struct fecha f1, struct fecha f2)
{
  int cant;
  if(f1.a==f2.a&&f1.m==f2.m)
    cant=f2.d-f1.d;
    else
    {
      cant=diasMes(f1.m,f1.a)-f1.d; //cantidad de dias al me siguiente
      f1.d=1; 
      f1.m++;
      if(f1.m>12)
      {
        f1.m=1;
        f1.a++
      }
      while(f1.a==f2.a&&f1.m<f2.m) //mientras mismo año y dia distinto voy sumando las fechas
      {
        cant=cant+diasMes(f.m,f.a)
        f1.d=1;
        f1.m++;
        if(f1.m>12)
        {
          f1.m=1;
          f1.a++;
        }
      }
      if(f1.m==f2.m){
      cant=cant+f2.d;}
      //pase de año
      while(f1.a<f2.a)
      {
        cant=cant+(esBisiesto(f.a)?366:365)
        f1.a++;
      }

//repetimos lo de arriba

//asterisco verde
      while(f1.a==f2.a&&f1.m<f2.m) //mientras mismo año y dia distinto voy sumando las fechas
      {
        cant=cant+diasMes(f.m,f.a)
        f1.d=1;
        f1.m++;
        if(f1.m>12)
        {
          f1.m=1;
          f1.a++;
        }
      }
      if(f1.m==f2.m){
      cant=cant+f2.d;}
//asterisco verde
    }
    return cant;          
  
    }