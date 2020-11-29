#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "pantalla.h"
#include "contratacion.h"




int main(void) {
	setbuf(stdout, NULL);
	char seguir='s';
	int bandera=0;
	char auxCuit[51];
	int idAux;
	Pantalla Pantallas[MAX_SRUCT_PANTALLAS];
	initList(Pantallas, MAX_SRUCT_PANTALLAS);
	Contratacion Contrataciones[MAX_CONTRATACIONES];
	contra_initList(Contrataciones, MAX_CONTRATACIONES);

	do
	{
		switch (menu())
		{
			case 1:
				add(Pantallas, MAX_SRUCT_PANTALLAS);
				bandera++;
				system("pause");
				system("cls");

				break;
			case 2:
				if(bandera>0)
				{
					if(modificar(Pantallas, MAX_SRUCT_PANTALLAS)!=-1)
					{
					printf("\nse pudo modificar correctamente");
					}else
					{
						printf("\nNo se pudo modificar");
					}

				}else
					printf("\nNo se ingreso ningun -------- todavia \n");

				break;
			case 3:
				removeNac(Pantallas, MAX_SRUCT_PANTALLAS);
				system("pause");
				system("cls");
				break;

			case 4 :
				pantalla_print(Pantallas, MAX_SRUCT_PANTALLAS);
				break;

			case 5 :
				contra_add(Contrataciones, MAX_CONTRATACIONES, Pantallas, MAX_SRUCT_PANTALLAS);
				break;

			case 6 :
				contra_print(Contrataciones, MAX_CONTRATACIONES);
				//contra_mostrarPanYCon(Contrataciones, MAX_CONTRATACIONES,"500", Pantallas, MAX_SRUCT_PANTALLAS);
				break;

			case 7 :
				if(utn_getCuit("ingresa el cuit que desea modificar =", "ingresa bien el cuit **-********-* ", auxCuit, 2, 51)==0)
				{
					contra_mostrarPanYCon(Contrataciones, MAX_CONTRATACIONES,auxCuit, Pantallas, MAX_SRUCT_PANTALLAS);
					utn_getInt("ingrese el id de la contratacion para continuar = ", "solamente numeros", &idAux, 2, 999, 0);
					contra_modificar(Contrataciones, MAX_CONTRATACIONES, contra_findId(Contrataciones, MAX_CONTRATACIONES, idAux));
				}

				break;
			case 8 :
					contra_remove(Contrataciones, MAX_CONTRATACIONES, Pantallas, MAX_SRUCT_PANTALLAS);
				break;
			case 10:
				 system("cls");
				 seguir='n';
				break;

	            default:
	                system("cls");
	                printf("\nIngrese opcion correcta\n\n");
	                break;
	        }
	                fflush(stdin);
	            }while (seguir=='s');

	return 0;
}


