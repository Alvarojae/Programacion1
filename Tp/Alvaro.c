#include <stdio.h>
#include <stdlib.h>

float factorialAC (float A)
{
    float factorial;
    float contador;
    contador=A;
    factorial=A;

    if(factorial>=0)
    {

    while(contador>1)
    {
        contador=contador-1;
        factorial=factorial*contador;
    }
    return factorial;
    }
    else
    {
        printf("No existe factorial negativo\n");
    }
    return 0;

}

float factorialBC(float B)
{
    float factorial;
    float contador;
    contador=B;
    factorial=B;
    if(factorial>0)
    {
    while(contador>1)
    {
        contador=contador-1;
        factorial=factorial*contador;
    }

    return factorial;
    }else
    {
        printf("No existe factorial negativo\n");
    }
    return 0;
}




   float sumaC(float A, float B)
   {
    float suma;
    suma=A+B;
    return suma;
   }

   float restaC(float A, float B)
   {
    float resta;
    resta=A-B;
    return resta;
   }

   float divicionC(float A, float B)
   {
       if(B==0)
       {
            printf("no se puede dividir por cero\n\n" );

       }else
       {
            float divicion;
            divicion=A/B;
            return divicion;
       }
    return 0;
   }

   float multiplcacionC(float A, float B)
   {
    float multiplicacion;
    multiplicacion=A*B;

    return multiplicacion;
   }

















