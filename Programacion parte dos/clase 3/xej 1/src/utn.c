
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float factorial(float x)
{

    float factorial;
    float contador;
    contador=x;
    factorial=x;

    if(factorial==0)
    {
        factorial=1;
        return factorial;
    }
    else
    {

    while(contador>1)
    {
        contador=contador-1;
        factorial=factorial*contador;
    }
    return factorial;

    }


}

float suma(float x, float y)
{
    float suma;
    suma=x+y;
    return suma;
}

float resta(float x, float y)
{
    float resta;
    resta=x-y;
    return resta;
}

float division(float x, float y)
{

    float divicion;
    divicion=x/y;
    return divicion;

}

float multiplicacion(float x, float y)
{
    float multiplicacion;
    multiplicacion=x*y;
    return multiplicacion;
}

















/*

int sumar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;

	*pResultado = operadorA + operadorB;
	retorno = 0;

	return retorno;
}

int restar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;

	*pResultado = operadorA - operadorB;
	retorno = 0;

	return retorno;
}

int dividir(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;

	if (operadorB != 0) {
		*pResultado = operadorA / operadorB;
		retorno = 0;
	}

	return retorno;
}

int multiplicar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;

	*pResultado = operadorA * operadorB;
	retorno = 0;

	return retorno;
}
*/
