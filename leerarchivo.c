int leerArchTxt(struct persona alu[])
{
  int cant=0;
  char nom[LNOM+1];
  FILE *pf=fopen("Lista.txt","st");
  if(pf==NULL)
  {
    printf("No se puede abrir el archivo \n");
    return 0;//return cant;
  }
  fgets(nom,LNOM,pf);
  while(!feof(pf))
  {
    *strchr(nom,'\n')='\o';
    strcpy(alu[cant].nombre,nom);
    fgets(alu[cant].tel,LTEL,pf);
    *strchr(alu[cant].tel,'\n')='\o';
    fscanf(pf,"%d",&alu[cant].dni);
    fgetc(pf); /* saco enter de arch */
    fscanf(pf,"%d/%d/%d",&alu[cant].nacim.d,&alu[cant].nacim.m,&alu[cant].nacim.a):
    fgetc(pf);//saco enter del archivo
    fgets(nom,LNOM+1,pf);
    cant++
  }
  fclose(pf);
  return cant;
}