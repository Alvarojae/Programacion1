/*
 ============================================================================
 Name        : punteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//------------------------------------------
int sumarEnteros(int operadorA, int operadorB);
int dividirEnteros(int operadorA, int operadorB,float *resultadoDividir);
//------------------------------------------
int main(void) {

	float resultadoDividir;

	int resultado;
	resultado = sumarEnteros(14,22);
	printf("el resultado es = %d",resultado);

	if(dividirEnteros(14, 22, &resultadoDividir) ==0)
	{
		printf("La divicion es =%f",resultadoDividir);
	}else
	{
		print("No se puede dividir por 0");
	}
	return EXIT_SUCCESS;
}

int sumarEnteros(int operadorA, int operadorB)
{
	int resultado;
	resultado = operadorA + operadorB;

	return resultado;
}




int dividirEnteros(int operadorA, int operadorB,float *resultadoDividir)
{
	int resultado= -1;
	if (operadorB != 0)
	{
		*resultadoDividir = (float)operadorA / operadorB;
		resultado = 0;
	}

	return resultado;
}








/*
if(operadorB !=0)
	{
		printf("La divicion es =%f",int dividirEnteros(int operadorA, int operadorB);
	}else
	{
		print("No se puede dividir por 0");
	}

/*
