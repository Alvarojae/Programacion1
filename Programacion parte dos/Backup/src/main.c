#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "Ventas.h"
#include "Clientes.h"
int main()
{
	setbuf(stdout, NULL);
	char seguir='s';
	int bandera=0;
	int banderaLoad=0;
    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaVentas= ll_newLinkedList();

    if((controller_loadFromTextDos("Clientes.csv",listaClientes)==0 &&
        controller_loadFromText("Ventas.csv",listaVentas)==0))
	{
		banderaLoad++;
	}
	else
		printf("no se pudo cargar los empleado\n");

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
			if(banderaLoad != 0)
			{
				if(controller_addCliente(listaClientes)==0)
					controller_saveAsText("Clientes.csv",listaClientes);
				else
					printf("No se pudo agregar el usuario");
			}else
				printf("Hubo un error en la carga del archivo\n");

			break;

		case 2:
			if(banderaLoad != 0)
				if(controller_addVentas(listaVentas,listaClientes)==0)
				{
					controller_saveAsTextVentas("Ventas.csv",listaVentas);
				}else
					printf("Hubo un error en la carga de la Venta\n");
			else
				printf("Hubo un error en la carga del archivo\n");
		   break;

		case 3:
			if(banderaLoad != 0)
			{
				if(controller_ModifyVentas(listaVentas, listaClientes)==0)
				  controller_saveAsTextVentas("Ventas.csv",listaVentas);
				else
					printf("Hubo un error en la modificacion de la Venta\n");
			}
			else
				printf("Hubo un error en la carga del archivo\n");
			break;

		case 4:
			if(banderaLoad != 0)
			{
				if(controller_cobrarVentas(listaVentas, listaClientes)==0)
				{
					controller_saveAsTextVentas("Ventas.csv",listaVentas);
				}else
					printf("Hubo un error para cobrar la Venta\n");
			}
			else
				printf("Hubo un error en la carga del archivo\n");
					break;

		case 5:
			if(banderaLoad != 0)
				controller_saveAsTextCobradas("ventasCobradas.csv", listaClientes, listaVentas,1);
			else
				printf("Hubo un error en la carga del archivo\n");
			break;
		case 6:
			if(banderaLoad != 0)
			{
				controller_saveAsTextCobradas("ventasConDeudas.csv", listaClientes, listaVentas,0);
			}else
			{
				printf("Hubo un error en la carga del archivo\n");
			}
			break;
		case 7:
			if(banderaLoad != 0)
			{
				controller_FindMaxAndMin(listaVentas, listaClientes, 0);
				controller_FindMaxAndMin(listaVentas, listaClientes, 1);
				controller_FindMaxAfichesVendidos(listaVentas, listaClientes);
			}else
				printf("Hubo un error en la carga del archivo\n");

			break;
		case 8:
			printf("id Ventas	id cliente	Cantidad de afiches 	Nombre del archivo	zona	estado\n");
			ll_map(listaVentas, returnMap1);
			printf("id cliente	cuit 	Nombre 	          Apellido\n");
			ll_map(listaClientes, returnMap);
				break;
		case 9:
			//Salir
			seguir='n';
			break;
	}
    }while(seguir=='s');

    return 0;
}

