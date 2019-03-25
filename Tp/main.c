#include <stdio.h>
#include <stdlib.h>

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
    float contadorFA;
    float contadorFB;

    printf("ingresar primer dato: ");
    scanf("%f", &A);

    printf("ingresar segundo dato; ");
    scanf("%f", &B);


    contadorFA=A;
    factorialA=A;
    while(contadorFA>1)
    {
        contadorFA=contadorFA-1;
        factorialA=factorialA*contadorFA;

    }

    contadorFB=B;
    factorialB=B;
    while(contadorFB>1)
    {
        contadorFB=contadorFB-1;
        factorialB=factorialB*contadorFB;

    }


    suma=A+B;
    resta=A-B;
    divicion=A/B;
    multiplicacion=A*B;




    printf("El resultado de A+B es: %f\n",suma);
    printf("El resultado de A-B es: %f\n",resta);
    printf("El resultado de A/B es: %f\n",divicion);
    printf("El resultado de A*B es: %f\n",multiplicacion);
    printf("El factorial de A es: %f y el factorial de %f es: \n",factorialA,factorialB);





    return 0;
}
