/* tiempo de permanencia */
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int he,me,hs,ms,hp,mf,hf;

	printf("Hora de Entrada:\n");
	scanf("%d:%d",&he,&me);
	printf("Hora de salida:\n");
	scanf("%d:%d",&hs,&ms);



	if (he>hs)
	{
		hp=((he*60)+me)-(hs*60+ms);
		hp=hp-24*60;
		hp=hp*-1;
	}else{
		hp=(hs*60+ms)-((he*60)+me);

		}
	hf=hp/60;
	mf=hp%60;//el modulo o resto 60 no devuelve de 70 - 60  nos devuelve 10 que son los minutos;


	printf("Permanencia\n%d:%d\n",hf,mf);



}




