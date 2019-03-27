#include <stdio.h>
#include <stdlib.h>

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

float divicion(float x, float y)
{

    float divicion;
    divicion=x/y;
    return divicion;

    return 0;
}

float multiplcacion(float x, float y)
{
    float multiplicacion;
    multiplicacion=x*y;

    return multiplicacion;
}

















