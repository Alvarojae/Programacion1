#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;


int main()
{
    eEmpleado* pemp = (eEmpleado*) malloc(sizeof(eEmpleado));
    if(pemp == NULL)
    {
        exit(1);
    }
    printf("ingrese legajo = ");
    scanf ("%d", &pemp->legajo);

    printf("ingrese nombre = ");
    fflush(stdin);
    //gets(pemp->nombre);
    scanf("%s", pemp->nombre);

    printf("ingrese sexo = ");
     fflush(stdin);
    scanf ("%c", &pemp->sexo);

     printf("ingrese sueldo = ");
    scanf ("%f", &pemp->sueldo);

    printf("legajo: %d nombre: %s sexo: %c  sueldo: %.2f\n",pemp->legajo,pemp->nombre,pemp->sexo,pemp->sueldo);

    printf("%d", sizeof(eEmpleado)); // -> muestra la cantidad de bits de sizeof de eEmpleado

    return 0;
}
