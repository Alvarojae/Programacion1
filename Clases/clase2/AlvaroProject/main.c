#include <stdio.h>
#include <stdlib.h>
#include "alvaro.h"

int main()
{

    int dato;
    int dato1;
    int dato2;
    int datoMayor;

    printf("ingrese primer dato\n");
    scanf("%d", &dato);

    printf("ingrese segundo dato\n");
    scanf("%d", &dato1);

    printf("ingrese tercer dato\n");
    scanf("%d", &dato2);


    datoMayor=numeroMayor( dato,  dato1, dato2);



    printf("el dato mayor es %d", datoMayor);






    return 0;
}




