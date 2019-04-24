#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#include "Empleados.h"
#define TAM 10
#define TAM2 4

int main()
{
    char confirma;

    sSector sectorcito[TAM2] = {
    {1, "RRHH"}
    ,{2, "Sistemas" }
    ,{3, "Peter" }
    ,{4, "Vegano" }
    };

    sEmpleado lista[TAM] = {
    {1, 1112, 32000, 'm', "Luchito",{2,6,2000},2}, {1, 1112, 32000, 'm', "Luchito2",{2,6,2000},1}, {1, 1111, 42000, 'm', "Peter", {2,6,2000},3}, {1, 1113, 200, 'm', "Alvaro", {2,6,2000},4}, {1, 1114, 42000, 'f', "Melana", {2,6,1980},3} };
    //borrarBaseDeDatos(lista,TAM);

    do {

        system("cls");

        switch (menuDeOpciones())
        {

        case 1:
            altaEmpleado(lista, TAM);
            system("pause");
            break;

        case 2:
            bajaEmpleado(lista, TAM);
            system("pause");
            break;

        case 3:
            modificacionEmpleado(lista, TAM);
            system("pause");
            break;

        case 4:
            printf("\ncomo desea ordenar las listas?\n\n");
            printf("1) Por legajo\n");
            printf("2) Alfabeticamente\n");
            printf("3) Por mayor sueldo\n");
            printf("4) Por menor sueldo\n\n");
            ordenarPor(lista, TAM);
            system("pause");
            break;

        case 5:
            mostrarPorSector(lista, sectorcito, TAM, TAM2);
            system("pause");
            break;

        case 6:
            printf("\nesta seguro que desea salir? (s/n): ");
            fflush(stdin);
            confirma = getche();

            while(tolower(confirma) != 's' && tolower(confirma) != 'n')
            {
                printf("\n\nEsa respuesta es invalida intente nuevamente...");
                printf("\n\nesta seguro que desea salir? (s/n): ");
                fflush(stdin);
                confirma = getche();
            }

            printf("\n");
            break;

        default:

            printf("\nEl comando ingresado es desconocido...\n\n");
            system("pause");
            break;
        }
    } while (confirma != 's');

    return 0;
}
