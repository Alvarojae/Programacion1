#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "empleados.h"

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Listar Sectores con Empleados\n");
    printf("7- Cantidad de empleados por sector\n");
    printf("8- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    obtenerSector(sectores, tam, emp.idSector, nombreSector);
    printf("   %d       %10s     %c    %.2f  %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, nombreSector);

}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int contador = 0;

    printf(" Legajo      Nombre        Sexo    Sueldo    Sector\n\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{

    int indice;
    int legajo;
    int esta;


    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", legajo);
            mostrarEmpleado(sectores, tamSector, vec[esta]);
        }
        else
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo );

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            vec[indice].ocupado = 1;

            printf("Alta empleado exitosa!!!\n\n");

        }
    }

}

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{

    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {

        if(idSector == sectores[i].id)
        {

            strcpy(desc, sectores[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}


void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{

    system("cls");
    for(int i=0; i < tamSec; i++)
    {
        printf("Sector: %s\n\n", sectores[i].descripcion);
        for(int j=0; j < tam; j++)
        {
            if( (empleados[j].idSector == sectores[i].id) && (empleados[j].ocupado == 1))
            {
                mostrarEmpleado(sectores, tamSec, empleados[j]);
            }
        }

        printf("\n\n");
    }




}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{

    int contador;
    system("cls");

    for(int i=0; i< tamSec; i++ )
    {
        contador = 0;
        printf("Sector: %s\n\n", sectores[i].descripcion);

        for(int j=0; j < tam; j++)
        {
            if(sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1)
            {
                contador++;
            }
        }

        printf("Cantidad: %d\n\n", contador);
    }
}
