/*
 ============================================================================
 Name        : ej1-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int maximo;
	int minimo;
	int dato;
	int flag = 0;
	char finalizar='n';

	while(finalizar!='s')
	{
		printf("Ingresa el  numero %d =",flag+1);
		scanf("%d",&dato);

		if(flag == 0)
		{
			maximo = dato;
			minimo = dato;
		}
		else
		{
			if (maximo < dato)
			{
				maximo = dato;
			}
			if(minimo > dato)
			{
				minimo = dato;
			}
		}
		fflush(stdin);
		printf("\ndesea terminar  s/n? =");
		scanf("%c",&finalizar);
		flag++;

	}
	printf("el valor minimo es = %d y el valor maximo es = %d", minimo,maximo);

	return EXIT_SUCCESS;
}







/*
 int main(void) {
	setbuf(stdout, NULL);
	int maximo;
	int minimo;
	int i;
	int dato;
	int flag = 1;
	char finalizar='n';


	for(i=0;i<5;i++)
	{


		printf("Ingresa el  numero %d =",i+1);
		scanf("%d",&dato);

		if(flag == 1)
		{
			maximo = dato;
			minimo = dato;
			flag++;
		}
		else
		{
			if (maximo < dato)
			{
				maximo = dato;
			}else
			{
				minimo = dato;
			}

		}

		printf("desea terminar  s/n? =");
		scanf("%c",&finalizar);

		if (finalizar=='s')
		{
			break;
		}

	}

	printf("el valor minimo es = %d y el valor maximo es = %d", minimo,maximo);



	return EXIT_SUCCESS;
}

 */


