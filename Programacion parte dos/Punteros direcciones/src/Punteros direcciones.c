/*
 ============================================================================
 Name        : Punteros.c
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

	int *pArrayA;

	pArrayA = (int*)malloc(sizeof(int)*2);
	if (pArrayA != NULL)
	{
		for(int i = 0; i< 2;i++)
		{
			printf("ingrese el %d valor = ",i);
			scanf("%d",(pArrayA+i));
			printf("direccion de memoria = %p \n",(&pArrayA+i));
			printf("valor de memoria = %d \n",*(pArrayA));
		}
		printf ("la cantidad de bits que tiene a es  = %d",sizeof(&pArrayA));
	}

	int *pAux;

	pAux=(int*)realloc(sizeof(int)*10);

	if(pAux != NULL)
	{
		pArrayA = pAux;
	}







	/*

	int *punteroInt;

	int auxInt;

	auxInt=10;
	punteroInt = &auxInt;
	printf("direccion de auxInt = %p \n",&auxInt);
	printf("direccion de punteroInt = %p \n",&punteroInt);

	printf("auxInt = %d \n",auxInt);
	printf("punteroInt = %p\n",punteroInt);
	printf("*punteroInt = %d\n",*punteroInt);
	printf("&punteroInt = %p\n",&punteroInt);
	*/
	return 1;
}
