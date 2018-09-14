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
