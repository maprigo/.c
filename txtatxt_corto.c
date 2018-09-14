#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    FILE * entr, *sal;
    int car, opc;

    entr = fopen("Origen.txt", "rt");
    if (entr==NULL)
    {

        printf("No se encontró arch. de entrada\n");
        return 1;
    }
    else
    {
        sal =fopen ("Destino.txt", "rt");
        if (sal != NULL)
        {
            printf("Desea sobreescribirlo? ");
            opc = fgetc(stdin);
            fgetc(stdin);
            if (toupper(opc)!='S')
            {
                printf("No se sobrescribe\n");
                fclose(entr);
                fclose(sal);
                return 1;
            }
            else
                fclose(sal);
        }
        car = fgetc(entr);
        while (!feof(entr))
        {
            fprintf(sal, "%c", (char)car);
            car = fgetc(entr);
        }
         fclose(entr);
         fclose(sal);
    }
    return 0;
}