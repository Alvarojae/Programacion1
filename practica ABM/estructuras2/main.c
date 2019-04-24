#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "empleados.h"



#define TAM 13
#define TAMSEC 5



int main()
{

    char seguir = 's';
    char confirma;
    eMenu menues[ ]={
        {1,"sopa"},
        {2,"ensalada"},
        {3,"milanesa"},
        {4,"tostadas"},
        {5,"pollo"},
        {6,"fideos"},
        {7,"sanguches"},
        {8,"tarta"},
        {9,"pizza"},
        {10,"hamburgesas veganas"},
    };


    eSector sectores[] =
    {
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Compras"},
        {4, "Ventas"},
        {5, "Legales"},

    };
    eEmpleado lista[TAM]=
    {
        {1234, "Juan", 'm', 30000,1, 1},
        {2222, "Ana", 'f', 32000, 2,1},
        {2211, "Jorge", 'm', 28000, 2,1},
        {3241, "Alberto", 'm', 35000,1, 1},
        {8944, "Sonia", 'f', 39000, 3,1},
        {2231, "Miguel", 'm', 29700, 4,1},
        {6578, "Adrian", 'm', 43200,5, 1},
        {3425, "Lucia", 'f', 32300, 2,1},
        {5546, "Gaston", 'm', 29760, 4,1},
        {7654, "Diego", 'm', 35000,1, 1},
        {9040, "Viviana", 'f', 47000, 1,1},
        {7439, "Gustavo", 'm', 25000, 4,1}
    };
    //inicializarEmpleados(lista, TAM);




    do
    {
        switch(menu())
        {

        case 1:
            //printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n\n");
            system("pause");
            break;

        case 3:
            printf("\nModificacion empleado\n\n");
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 6:
            //printf("\nListar empleados\n\n");
            mostrarSectoresConEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
         case 7:
            //printf("\nListar empleados\n\n");
            mostrarCantEmpleadosXSector(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 8:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}


