#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "publicacion.h"
#include "cliente.h"
#include "informes.h"


int main(void) {
	setbuf(stdout, NULL);
	char seguir='s';
	int bandera=0;
	Cliente Clientes[MAX_SRUCT_CLIENTES];
	cliente_initList(Clientes, MAX_SRUCT_CLIENTES);
	Publicacion Publicaciones[MAX_PUBLICACIONES];
	publicacion_initList(Publicaciones, MAX_PUBLICACIONES);

	//clientes forzados
	cliente_altaForzada(Clientes, MAX_SRUCT_CLIENTES,"juan","Alvaro","20-16597452-9");
	cliente_altaForzada(Clientes, MAX_SRUCT_CLIENTES,"jose","Perez","20-12643526-9");
	cliente_altaForzada(Clientes, MAX_SRUCT_CLIENTES,"Noco","Lomo","20-79164125-9");
	cliente_altaForzada(Clientes, MAX_SRUCT_CLIENTES,"leandro","Merino","20-12387456-9");
	cliente_altaForzada(Clientes, MAX_SRUCT_CLIENTES,"Claudio","Zapallo","20-12347865-9");
	//publicaciones forzados
	//publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,2,3,"Vendo clio 2010");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,3,4,"Vendo carros");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,3,2,"Vendo carros");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,1,3,"Vendo autos");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,3,4,"Vendo carros");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,2,4,"Vendo motos");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,3,3,"Vendo carros");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,3,3,"Vendo carros");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,2,4,"Vendo motos");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,2,4,"Vendo motos");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,2,4,"Vendo motos");
	publicacion_altaForzada(Publicaciones, MAX_PUBLICACIONES,3,3,"Vendo carros");




	do
	{
		if(bandera!=0)
		{
			system("pause");
			system("cls");
		}
		bandera++;

		switch (menu())
		{
			case 1:
				if(cliente_buscarLibre(Clientes, MAX_SRUCT_CLIENTES)!=-1)
				{
					cliente_add(Clientes, MAX_SRUCT_CLIENTES);
					bandera++;
					system("pause");
					system("cls");
				}else
					printf("\nNo hay espacion para agregar mas clientes");


				break;
			case 2:
				if(cliente_buscarUsuarioDeAlta(Clientes, MAX_SRUCT_CLIENTES)!=-1)
				{
					if(cliente_modificar(Clientes, MAX_SRUCT_CLIENTES)!=-1)
					{
					printf("\nse pudo modificar correctamente");
					}else
					{
						printf("\nNo se pudo modificar");
					}
				}else
					printf("\nNo se ingreso ningun cliente todavia \n");

				break;
			case 3:
				if(cliente_buscarUsuarioDeAlta(Clientes, MAX_SRUCT_CLIENTES)!=-1 &&
				   publicacion_buscarUsuarioDeAlta(Publicaciones, MAX_PUBLICACIONES)!=-1)
				{
					cliente_remove(Clientes, MAX_SRUCT_CLIENTES,Publicaciones, MAX_PUBLICACIONES);
				}else
					printf("\nNo se ingreso ningun cliente todavia \n");

				break;

			case 4 :
				if(publicacion_buscarLibre(Publicaciones, MAX_PUBLICACIONES)!=-1)
				{
					if(cliente_buscarUsuarioDeAlta(Clientes, MAX_SRUCT_CLIENTES)!=-1)
					{
						publicacion_add(Publicaciones, MAX_PUBLICACIONES, Clientes, MAX_SRUCT_CLIENTES);
					}else
						printf("\nNo se ingreso ningun cliente todavia \n");
				}else
					printf("\nNo hay espacio para agregar mas publicaciones");

				break;

			case 5 :
				if(cliente_buscarUsuarioDeAlta(Clientes, MAX_SRUCT_CLIENTES)!=-1 &&
				   publicacion_buscarUsuarioDeAlta(Publicaciones, MAX_PUBLICACIONES)!=-1)
				{
					mostrarPublicacionesPausadasOActivas(Publicaciones, MAX_PUBLICACIONES, 1);
					pausarPublicacion(Publicaciones, MAX_PUBLICACIONES,Clientes, MAX_SRUCT_CLIENTES);
				}else
					printf("\nNo se ingreso ninguna Publicacion todavia \n");
				break;

			case 6 :
				if(cliente_buscarUsuarioDeAlta(Clientes, MAX_SRUCT_CLIENTES)!=-1 &&
				   publicacion_buscarUsuarioDeAlta(Publicaciones, MAX_PUBLICACIONES)!=-1)
				{
					if(ContadorDeInactivas(Publicaciones, MAX_PUBLICACIONES)!=0)
				{
					mostrarPublicacionesPausadasOActivas(Publicaciones, MAX_PUBLICACIONES, 0);
					reanudarPublicacion(Publicaciones, MAX_PUBLICACIONES,Clientes, MAX_SRUCT_CLIENTES);
				}else
					printf("\nNo hay ninguna publicacion dada de baja \n");
				}else
					printf("\nNo se ingreso ninguna Publicacion todavia \n");
				break;
			case 7 :
				if(cliente_buscarUsuarioDeAlta(Clientes, MAX_SRUCT_CLIENTES)!=-1 &&
				   publicacion_buscarUsuarioDeAlta(Publicaciones, MAX_PUBLICACIONES)!=-1)
				{
					publicacion_imprimirClientes(Clientes, MAX_SRUCT_CLIENTES, Publicaciones, MAX_PUBLICACIONES);

				}else
				printf("\nNo se ingreso ninguna Publicacione todavia \n");

				break;

			case 8 :
				switch (informes())
				{

					case 1:
						if(cliente_buscarUsuarioDeAlta(Clientes, MAX_SRUCT_CLIENTES)!=-1 &&
						   publicacion_buscarUsuarioDeAlta(Publicaciones, MAX_PUBLICACIONES)!=-1)
						{
							contadorClienteConMasAvisos(Clientes, MAX_SRUCT_CLIENTES, Publicaciones, MAX_PUBLICACIONES);
						}else
							printf("\nNo se ingreso ninguna Publicacione todavia \n");
						break;

					case 2:
						if(ContadorDeInactivas(Publicaciones, MAX_PUBLICACIONES)!=-1)
						{
							printf("La cantidad de avisos pausados son %d \n",ContadorDeInactivas(Publicaciones, MAX_PUBLICACIONES));
						}else
						{
							printf("no hay avisos pausados");
						}
						break;

					case 3:
						if(publicacion_buscarLibre(Publicaciones, MAX_PUBLICACIONES)!=-1)
						{
							contarRubroConMasAvisos(Publicaciones, MAX_PUBLICACIONES);
						}else
							printf("\nNo se ingreso ninguna Publicacion todavia \n");

						break;

					case 4:
						if(cliente_buscarUsuarioDeAlta(Clientes, MAX_SRUCT_CLIENTES)!=-1 &&
						   publicacion_buscarUsuarioDeAlta(Publicaciones, MAX_PUBLICACIONES)!=-1)
						{
							contadorClienteConMasAvisosActivosOPausados(Clientes, MAX_SRUCT_CLIENTES, Publicaciones, MAX_PUBLICACIONES,1);
						}else
							printf("\nNo se ingreso ninguna Publicacion o cliente todavia \n");

						break;

					case 5:
						if(publicacion_buscarLibre(Publicaciones, MAX_PUBLICACIONES)!=-1 &&
						   publicacion_buscarUsuarioDeAlta(Publicaciones, MAX_PUBLICACIONES)!=-1 &&
						   ContadorDeInactivas(Publicaciones, MAX_PUBLICACIONES)!=0)
						{
							contadorClienteConMasAvisosActivosOPausados(Clientes, MAX_SRUCT_CLIENTES, Publicaciones, MAX_PUBLICACIONES,0);
						}else
							printf("\nNo se ingreso ninguna Publicacion pausada todavia \n");

						break;

					case 6:
						printf("Saliste de informes\n");
						break;

				}

				break;
			case 9:
				 system("cls");
				 seguir='n';
				break;

			case 10 :
				switch (Testeo())
				{
					case 1:
						cliente_print(Clientes, MAX_SRUCT_CLIENTES);
					break;

					case 2:
						publicacion_print(Publicaciones, MAX_PUBLICACIONES);
					break;

					case 3:
						//publicacion_modificar(Publicaciones, MAX_PUBLICACIONES);
					break;
					case 4:
						//cliente_sortByName(Clientes, MAX_SRUCT_CLIENTES, 1);
					break;
					case 5:
						//publicacion_sortByRubro(Publicaciones, MAX_PUBLICACIONES, 0);

					break;
					case 6:

					break;
				}
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


