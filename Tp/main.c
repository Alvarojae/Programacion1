#include <stdio.h>
#include <stdlib.h>
#include "alvaro.h"

int main()
{

    float A;
    float B;
    float suma;
    float resta;
    float divicion;
    float multiplicacion;
    float factorialA;
    float factorialB;

    printf("ingresar primer dato: ");
    scanf("%f", &A);

    printf("ingresar segundo dato: ");
    scanf("%f", &B);

    factorialA=factorialAC (A);
    factorialB=factorialBC(B);
    suma=sumaC(A,B);
    resta=restaC(A,B);
    divicion=divicionC(A,B);
    multiplicacion=multiplcacionC(A,B);

    printf("El resultado de A+B es: %.0f\n",suma);
    printf("El resultado de A-B es: %.0f\n",resta);
    printf("El resultado de A/B es: %.2f\n",divicion);
    printf("El resultado de A*B es: %.0f\n",multiplicacion);
    printf("El factorial de  A  es: %.0f\n",factorialA);
    printf("El factorial de  B  es: %.0f\n",factorialB);

    return 0;
}
