#include <stdio.h>
#include <stdlib.h>
//------------------------------------------
int sumarEnteros(float operadorA, float operadorB);
int dividirEnteros(float operadorA, float operadorB,float *resultadoDividir);
int restarEnteros(float operadorA, float operadorB);
int multiplicarEnteros(float operadorA, float operadorB);
//------------------------------------------
int main(void) {

	float resultadoDividir;
	int resultado;
	float operadorA;
	float operadorB;

	printf("ingrese el primer numero = ");
	fflush(stdin);
	scanf("%f",&operadorA);

	printf("ingrese el segundo numero = ");
	fflush(stdin);
	scanf("%f",&operadorB);

	printf("el resultado de la sumatoria es = %d",sumarEnteros(operadorA,operadorB));
	printf("\nel resultado de la resta es = %d", restarEnteros(operadorA,operadorB));
	printf("\nel resultado de la multiplicacion es = %d",multiplicarEnteros(operadorA,operadorB));

	if(dividirEnteros(operadorA, operadorB, &resultadoDividir) ==0)
	{
		printf("La divicion es =%f",resultadoDividir);
	}else
	{
		printf("No se puede dividir por 0");
	}
	return EXIT_SUCCESS;
}

int sumarEnteros(float operadorA, float operadorB)
{
	int resultado;
	resultado = operadorA + operadorB;

	return resultado;
}
int restarEnteros(float operadorA, float operadorB)
{
	int resultado;
	resultado = operadorA - operadorB;

	return resultado;
}
int multiplicarEnteros(float operadorA, float operadorB)
{
	int resultado;
	resultado = operadorA * operadorB;

	return resultado;
}

int dividirEnteros(float operadorA, float operadorB,float *resultadoDividir)
{
	int resultado= -1;
	if (operadorB != 0)
	{
		*resultadoDividir = (float)operadorA / operadorB;
		resultado = 0;
	}

	return resultado;
}

