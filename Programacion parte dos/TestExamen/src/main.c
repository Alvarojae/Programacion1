#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Envio.h"
#include "utn.h"

int main()
{
	setbuf(stdout, NULL);
	char seguir='s';
	int bandera=0;
	int banderaLoad=0;

    LinkedList* listaEnvios = ll_newLinkedList();

    do{
    	if(bandera!=0)
		{
			system("pause");
			system("cls");
		}
		bandera++;
        switch(menu())
        {
            case 1:
            	if(banderaLoad == 0)
				{
					if(controller_loadFromText("data.csv",listaEnvios)==0)
					{
						printf("se cargo correctamente los empleado\n");
						banderaLoad++;
					}
					else
						printf("no se pudo cargar los empleado\n");
				}else
					printf("Ya se cargo los usuarios\n");
                // Cargar los datos (data.csv)
                break;


            case 2:
            	if(banderaLoad != 0)
					if(controller_ListEnvio(listaEnvios)==0)
						printf("\n");
					else
						printf("No se pudo mostrar los empleados\n");
				else
					printf("Se deben cargar los usuarios primero\n");
			   break;
            case 3:
            	if(banderaLoad != 0)
            	{
            		ll_map(listaEnvios, calcularCostos);
            		controller_ListEnvio(listaEnvios);
            	}
            	else
					printf("Se deben cargar los usuarios primero\n");
            	break;

            case 4:
            	if(banderaLoad != 0)
            	{
            		controller_zonas(listaEnvios);
            	}
            	else
					printf("Se deben cargar los usuarios primero\n");
                       	break;

            case 5:
            	if(banderaLoad != 0)
            	{

            		controller_zonasNoRepetidas(listaEnvios);

            		//generarListaZona(listaEnvios);
            		//LinkedList* aux = ll_clone(listaEnvios);
					ll_sort(aux, sortZona, 1);

            		//printTest(aux);
            		//controller_ListEnvio(aux);

            		//controller_zonasNoRepetidas(listaEnvios);
            		//zona_imprimir(listaEnvios);
            	}
            	else
					printf("Se deben cargar los usuarios primero\n");
                       	break;
            case 6:
            	//Salir
            	seguir='n';
				break;
        }
    }while(seguir=='s');
    return 0;
}
