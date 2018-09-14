#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b;
	printf("ingrese numero\n");
	scanf("%d", &a);
	printf("ingrese numero\n");
	scanf("%d", &b);

	if (a%b == 0) {
		printf("a es multiplo de b\n");
	}
	else if (b%a == 0)
	{
		printf(" b es multiplo a\n");
	}
	else
	{
		printf("no son multiplos\n");
	}
	return 0;
}

