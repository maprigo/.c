//copiar un archivo de texto en otro
#include<stdio.h>
#include<ctype.h>
int main(void)
{
	FILE *entrada, *salida; //Declaro dos punteros archivos, uno de entrada y otro de salida.
	int car, opc; //declaro una variable entera
	entrada = fopen("origen.txt", "rt");
	if (entrada != NULL)
	{
		salida = fopen("destino.txt", "rt");
		if (salida != NULL)
		{
			printf("Desea sobre escribir el archivo (S/N)?");
			opc = fgetc(stdin);
			if (toupper(opc) == 's')
			{
				fclose(salida);
				salida = fopen("destino.txt", "wt");
				if (salida != NULL)
				{
					car = fgetc(entrada);
					while (!feof(entrada))
					{
						fprintf(salida, "%c", (char)car);
						car = fgetc(entrada);
					}
					fclose(salida);
					fclose(entrada);
				}
				else
				{
					fclose(entrada);
				}
			}	
			else
			{
				fclose(entrada);
			}
			
		}
		else
		{
			salida = fopen("destino.txt", "wt");
			if (salida = NULL)
			{
				fclose(entrada);
			}
			else
			{
				car = fgetc(entrada);
				while (!feof(entrada))
				{
					fprintf(salida, "%c", (char)car);
					car = fgetc(entrada);
				}
				fclose(salida);
				fclose(entrada);
			}
		}
	}
	else
	{
		printf("Archivo de entrada no encontrado\n");
	}
	return 0;
}

void guardarArchTxt(struct persona alu[],init cant)
{
  FILE *pf=fopen("Lista.txt","wt");
  int i;
  if (pf)
  {
    for(i=0;i<cant;i++)
      {
        fprintf(pf,"%s\n",alu[i].nombre);
        fprintf(pf,"%s\n",alu[i].tel);
        fprintf(pf,"%s\n",alu[i].dni);
        fprintf(pf,"%s\n",alu[i].nombre);
        fprintf(pf,"%s\n",alu[i].nombre);
        fprintf(pf,"%s\n",alu[i].alu[i].nacim.d,alu[i].nacim.m,alu[i].nacim.a);
      }
      fclose(pf);
  }
  else
  {
      printf("No se puede abrir el archivo \n");
  }
}