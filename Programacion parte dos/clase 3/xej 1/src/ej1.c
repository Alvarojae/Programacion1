
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
	setbuf(stdout, NULL);

    float a;
    float b;
    int numero;
    int bandera;
    float sumaX;
    float restaX;
    float divisionX;
    float multiplicacionX;
    float factorialA;
    float factorialB;
    int entrada3;

    bandera=0;
    a=0;
    b=0;
    entrada3=0;


    while(bandera==0)
    {
    printf("\nIngrese un numero del 1-5 \n");
    printf("1-Para ingresar primer numero (A=%.0f)\n",a);
    printf("2-Para ingresar segundo numero (B=%.0f)\n",b);
    printf("3-Para calcular las operaciones\n");
    printf("4-Para informar los resultados\n");
    printf("5-Salir\n");
    scanf("%d", &numero);
    fflush(stdin);

    switch(numero)
    {
        case 1:
        printf("ingresar primer dato: ");
        scanf("%f", &a);

        break;
        case 2:
        printf("ingresar segundo dato: ");
        scanf("%f", &b);


        break;
        case 3:

        entrada3=1;
        sumaX=suma(a, b);
        restaX=resta(a, b);
        divisionX=division(a, b);
        multiplicacionX=multiplicacion(a, b);
        factorialA=factorial(a);
        factorialB=factorial(b);
        printf("\nSe han calculado todas las operaciones\n");


        break;
        case 4:
        if(entrada3==1)
        {
            printf("\nEl resultado de A+B es: %.0f\n",sumaX);
            printf("El resultado de A-B es: %.0f\n",restaX);

        if(b==0)
        {
            printf("No se puede dividir por cero\n");
        }else
        {
             printf("El resultado de A/B es: %.2f\n",divisionX);
        }

        printf("El resultado de A*B es: %.0f\n",multiplicacionX);

        if(a<0)
        {
            printf("No existe factoriales negativos\n");
        }else
        {
            printf("El factorial de  A  es: %.0f\n",factorialA);
        }

        if(b<0)
        {
            printf("No existe factoriales negativos\n");
        }else
        {
            printf("El factorial de  B  es: %.0f\n",factorialB);
        }
        }else
        {
            printf("No calculaste las operaciones \n");
        }


        break;
        case 5:
        bandera=1;
        break;



    }



}
}




/*

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void) {


	float numUno;
	float numDos;
	int resultadoScan;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;

	printf("\nIngrese el primer operando: ");
	fflush(stdin);
	resultadoScan = scanf("%f", &numUno);
	while (resultadoScan == 0) {
		printf("\nError, Ingrese un numero: ");
		fflush(stdin);
		resultadoScan = scanf("%f", &numUno);
	}
	printf("\nIngrese el segundo operando: ");
	fflush(stdin);
	resultadoScan = scanf("%f", &numDos);
	while (resultadoScan == 0) {
		printf("\nError, Ingrese un numero: ");
		fflush(stdin);
		resultadoScan = scanf("%f", &numDos);
	}

	if (sumar(numUno, numDos, &resultadoSuma) == 0) {
		printf("\nEl resultado de la suma es: %.2f", resultadoSuma);
	} else {
	    printf("\nAlgo salio mal");
	}
	if (restar(numUno, numDos, &resultadoResta) == 0) {
		printf("\nEl resultado de la resta es: %.2f", resultadoResta);
	} else {
	    printf("\nAlgo salio mal");
	}
	if (dividir(numUno, numDos, &resultadoDivision) == 0) {
		printf("\nEl resultado de la division es: %.2f", resultadoDivision);
	} else {
		printf("\nNo se puede dividir por 0");
	}
	if (multiplicar(numUno, numDos, &resultadoMultiplicacion) == 0) {
		printf("\nEl resultado de la multiplicacion es: %.2f",
				resultadoMultiplicacion);
	}else {
		printf("\nAlgo salio mal");
	}

	return EXIT_SUCCESS;
}

*/

