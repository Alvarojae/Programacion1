#include <stdio.h>
#include <stdlib.h>
#include "alvaro.h"

int main()
{

    float A;
    float B;

    printf("ingresar primer dato: ");
    scanf("%f", &A);

    printf("ingresar segundo dato: ");
    scanf("%f", &B);


    printf("El resultado de A+B es: %.0f\n",suma(A,B));
    printf("El resultado de A-B es: %.0f\n",resta(A,B));

    if(B==0)
    {
        printf("Error\n");
    }else
    {
         printf("El resultado de A/B es: %.2f\n",divicion(A,B));
    }

    printf("El resultado de A*B es: %.0f\n",multiplcacion(A,B));

    if(A<0)
    {
        printf("Error\n");
    }else
    {
        printf("El factorial de  A  es: %.0f\n",factorial(A));
    }

    if(B<0)
    {
        printf("Error\n");
    }else
    {
        printf("El factorial de  A  es: %.0f\n",factorial(B));
    }

    return 0;
}
