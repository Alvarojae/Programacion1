#include <stdio.h>
#include <stdlib.h>
float dividirEnteros(float operadorA, float operadorB);
float ingresarNumero(float dato);
int sumar(float dato,float dato2);
int restar(float dato,float dato2);
int multiplicar(float dato,float dato2);

int main()
{
    float dato=0;
    float dato2=0;

    dato=ingresarNumero(dato);
    dato2=ingresarNumero(dato2);

    printf("La suma es =%d\n",sumar(dato,dato2));
    printf("La resta es =%d\n",restar(dato,dato2));

    if(dato2!=0)
    {
        printf("La divicion es =%f\n",dividirEnteros(dato,dato2));
    }
    else
    {
        printf("no se puede divir por 0 \n");
    }

    printf("La multiplicacion es =%d\n",multiplicar(dato,dato2));

    return 0;
}


int multiplicar(float dato,float dato2)
{
    int aux=0;
    aux=dato*dato2;
    return aux ;
}

int restar(float dato,float dato2)
{
    int aux=0;
    aux=dato-dato2;
    return aux ;
}

int sumar(float dato,float dato2)
{
    int aux=0;
    aux=dato+dato2;
    return aux ;
}

float ingresarNumero(float dato)
{
    printf("\n ingrese un numero =");
    fflush(stdin);
    scanf("%f",&dato);
    return dato;
}

float dividirEnteros(float operadorA, float operadorB)
{
    float respuesta=0;
    respuesta = operadorA / operadorB;
	return respuesta;
}
