#include <stdio.h>
#include <stdlib.h>

void main()
{


    float numUno;
    int resultadoScan;
    printf("\nIngrese el primer operando: ");
	fflush(stdin);
	resultadoScan = scanf("%f", &numUno);
	while(resultadoScan==0)
    {
        printf("\nIngrese el primer operando: ");
        fflush(stdin);
        resultadoScan = scanf("%f", &numUno);
        printf("\nel numero es: %d",resultadoScan);
    }
    printf("\nel numero es: %.2f",numUno);


    printf("\nel numero es: %d",resultadoScan);



}


