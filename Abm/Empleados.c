#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#include "Empleados.h"
#include "Input.h"

#define TAM2 4

int menuDeOpciones()
{
    int opcion;

    printf("-----ABM de empleados UwU-----");
    printf("\n1) Alta empleado");
    printf("\n2) Baja empleado");
    printf("\n3) Modificar empleado");
    printf("\n4) Ordenar empleados");
    printf("\n5) Lista de empleados");
    printf("\n6) Salir");
    printf("\n\n... Que desea hacer?: ");

    scanf("%d", &opcion);

    return opcion;
}

void borrarBaseDeDatos(sEmpleado vec[], int tam)
{
    for(int i=0; i< tam; i++)
    {
        vec[i].estado = 0;
    }

}

void mostrarEmpleado (sEmpleado emp, sSector sector[], int tam)
{
    char descripcion[20];
    obtenerSector(sector, tam, emp.idSectores, descripcion);
    printf("%8d  %10s  %6c  %8.f  %2d/%d/%d %s \n", emp.legajo, emp.nombre, emp.genero, emp.sueldo, emp.fechNac.dia, emp.fechNac.mes, emp.fechNac.year, descripcion);
}

void mostrarGrupo ( sEmpleado emp[], int tam, sSector sectorcito[])
{
    printf("\n  Legajo      Nombre  Genero    Sueldo  D/MM/AAAA\n\n");
    for (int i=0; i < tam; i++)
    {
        if (emp[i].estado == 1)
        {
           mostrarEmpleado(emp[i], sectorcito, TAM2);
        }
    }
}

int buscarEspacioLibre (sEmpleado emp[], int tam)
{
    int indice = -1;

    for (int i = 0; i < tam; i++)
    {
        if (emp[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(sEmpleado emp[], int tam, int legajo)
{
    int indice = -1;

    for (int i = 0; i < tam; i++)
    {
        if (emp[i].estado == 1 && emp[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado (sEmpleado emp[], int tam)
{
    int respuesta;
    int legajo;
    int indice = buscarEspacioLibre(emp, tam);

    if (indice == -1)
    {
        printf("\n no hay mas espacio en el sistema :c");
    }
    else
    {
        printf("\nIngrese numero de legajo: ");
        scanf("%d", &legajo);

        int esta = buscarEmpleado(emp, tam, legajo);

        if(esta != -1)
        {
            printf("este empleado ya existe en el sistema\n");
        }
        else
        {
            fflush(stdin);
            emp[indice].legajo = legajo;


            do {
                respuesta = getString(emp[indice].nombre,"Ingrese nombre del empleado: ","Error, intentelo nuevamente\n",0,20);
                fflush(stdin);
            } while ( respuesta == -1 );

            /*do {
                respuesta = getInt(&emp[indice].sector, "Ingrese sector de trabajo\n\n1) Sector de recursos humanos\n2) Sector de sistemas\n3) Sector de gente que trabaja para peter\n", "Error, intentelo nuevamente\n", 1, 3);
                fflush(stdin);
            } while ( respuesta == -1);*/


            printf("Ingrese su genero: ");
            scanf("%c", &emp[indice].genero );
            fflush(stdin);

            printf("Ingrese sueldo: ");
            scanf("%f", &emp[indice].sueldo );
            fflush(stdin);

            printf("Ingrese dia de nacimiento: ");
            scanf("%d", &emp[indice].fechNac.dia );
            fflush(stdin);

            printf("Ingrese mes de nacimiento: ");
            scanf("%d", &emp[indice].fechNac.mes );
            fflush(stdin);

            printf("Ingrese el year de nacimiento: ");
            scanf("%d", &emp[indice].fechNac.year );

            emp[indice].estado = 1;

            printf("Alta empleado exitosa!!!\n\n");
        }
    }
}

void bajaEmpleado (sEmpleado emp[], int tam)
{
    int legajo;
    int indice;
    char respuesta;

    printf("\ningrese numero de legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(emp, tam, legajo);

    if ( indice == -1)
    {
        printf("\neste empleado no existe en el sistema.\n");
    }
    else
    {
        printf("\nesta seguro de que quiere dar de alta a este empleado...?\n");
        printf("\n  Legajo  Nombre  Genero    Sueldo\n");

        printf("\n(s/n): ");

        respuesta = getche();
        respuesta = tolower(respuesta);

        while (respuesta != 's' && respuesta != 'n')
        {
            system("cls");
            printf("Esa respuesta es invalida intente nuevamente...");
            printf("\n\nesta seguro de que quiere dar de alta a este empleado...?\n");
            printf("\n  Legajo  Nombre  Genero    Sueldo\n");
            printf("\n(s/n): ");
            respuesta = getche();
            respuesta = tolower(respuesta);
        }

        if (respuesta== 's')
        {
            emp[indice].estado = 0;
            printf("\n\nel empleado se dio de baja correctamente!\n\n");
        }
        else
        {
            printf("\nVolviendo al menu...\n");
        }
    }
}

void modificacionEmpleado (sEmpleado emp[], int tam)
{
    int legajo;
    int indice;
    printf("\ningrese legajo: ");
    fflush(stdin);
    scanf("%d", &legajo);

    indice = buscarEmpleado(emp, tam, legajo);

    if (indice == -1)
    {
        printf("\nEl empleado a modificar no existe en el sistema\n\n");
    }
    else
    {
        printf("\nIngrese el monto de sueldo a modificar: ");
        scanf("%f", &emp[indice].sueldo);
        printf("\nse modifico el sueldo correctamente");
    }

}


void ordenarPor(sEmpleado emp[], int tam)
{
    sEmpleado auxemp[tam];
    int opcion;

    printf("Orden por... ");
    scanf("%d", &opcion);

    for (int i = 0; i < tam; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            switch (opcion)
            {
                case 1:
                    if(emp[i].legajo > emp[j].legajo)
                    {
                        auxemp[0] = emp[i];
                        emp[i] = emp[j];
                        emp[j] = auxemp[0];
                    }
                    break;

                case 2:
                    /*if(stricmp(emp[i].nombre, emp[j].nombre) == 1)
                    {
                        auxemp[0] = emp[i];
                        emp[i] = emp[j];
                        emp[j] = auxemp[0];
                    }*/
                    break;

                case 3:
                    if(emp[i].sueldo < emp[j].sueldo)
                    {
                        auxemp[0] = emp[i];
                        emp[i] = emp[j];
                        emp[j] = auxemp[0];
                    }
                    break;

                case 4:
                    if(emp[i].sueldo > emp[j].sueldo)
                    {
                        auxemp[0] = emp[i];
                        emp[i] = emp[j];
                        emp[j] = auxemp[0];
                    }
                    break;

                default:
                    break;
            }
        }
    }
}

void obtenerSector (sSector sectores[], int tam, int id, char desc[])
{
    for (int i = 0; i < tam; i++)
    {
        if ( id == sectores[i].id )
        {
            strcpy(desc, sectores[i].descripcion);
            break;
        }
    }
}

void mostrarPorSector ( sEmpleado emp[], sSector succ[], int tam, int tam2)
{
    for ( int i = 0; i < tam2; i++ )
    {
        printf("sector: %s\n\n", succ[i].descripcion);
        for (int j = 0; j < tam; j++ )
        {
            if ( emp[j].idSectores == succ[i].id && emp[j].estado == 1)
            {
                mostrarEmpleado(emp[j],succ,tam);
            }
        }
    }
}
