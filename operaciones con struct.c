//operaciones con struct 
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
    scanf("%d/%d/%d/",&f->d,&f->m,&f->a); //para acceder a una indirección 
  } while(!esFechaGregoriana(*f));
}

void mostrar(struct fecha f)
{
  prinf("%02d-%02d-%4d\n",f.d,f.m,f.a);
}
