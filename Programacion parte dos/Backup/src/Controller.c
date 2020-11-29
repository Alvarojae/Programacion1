#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Ventas.h"
#include "Clientes.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* direccion del archico
 * \param pArrayListEnvio LinkedList* direccion de la linked list
 * \return int 0 ok
 *
 */
int controller_loadFromText(char* path , LinkedList* pArray)
{
		int retorno=-1;
		FILE* file;
		if(path != NULL && pArray !=NULL)
		{
			file = fopen(path, "r");
			if(parser_EnvioFromText(file, pArray)==0)
			{
				retorno = 0;
			}else
			{
				file = fopen(path, "w");
				printf("No existia el archivo y fue creado\n");
				retorno = 0;
			}
		}
		fclose(file);
	    return retorno;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */

int controller_loadFromTextDos(char* path , LinkedList* pArray)
{
		int retorno=-1;
		FILE* file;
		if(path != NULL && pArray !=NULL)
		{
			file = fopen(path, "r");
			if(parser_EnvioFromTextDos(file, pArray)==0)
			{
				retorno = 0;
			}else
			{
				file = fopen(path, "w");
				printf("No existia el archivo y fue creado\n");
				retorno = 0;
			}
		}
		fclose(file);
	    return retorno;

}
/** \brief Alta de cliente, da de alta un cliente
 *
 * \param pArrayListEmployee LinkedList* Direccion de la lista enlazada
 * \return int 0 ok
 *
 */
int controller_addCliente(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    char auxNombre[128];
    char auxApellido[128];
    char auxCuit[128];
    Clientes* cliente = Clientes_new();
    if(cliente != NULL && pArrayListEmployee != NULL)
    {
    	if(	utn_getNombre("ingrese el Nombre =", "ingrese correctamente el nombre\n", auxNombre, 3, 128)==0 		&&
			utn_getNombre("ingrese el Apellido =", "ingrese correctamente el Apellido\n", auxApellido, 3, 128)==0 &&
			utn_getCuit("ingrese el Cuit =", "ingrese correctamente el Cuit\n", auxCuit, 3, 128)==0 &&
			cuitRepetido(pArrayListEmployee, auxCuit)!=-1)
		{
    		if((Clientes_set_nombre(cliente, auxNombre)==0 &&
				Clientes_set_apellido(cliente, auxApellido) ==0 &&
				Clientes_set_cuit(cliente, auxCuit)==0 &&
				Clientes_set_idCliente(cliente, controller_FindNextIdClientes(pArrayListEmployee)) == 0 ))
    		{
    			printf("id:%d| cuit:%s| nombre:%s| Apellido:%s\n",controller_FindNextIdClientes(pArrayListEmployee),auxCuit,auxNombre,auxApellido);
    			ll_add(pArrayListEmployee, cliente);
    			retorno = 0;
    		}
		}else
			printf("El cuit esta repetido\n");
    }
    return retorno;
}

/** \brief Alta de cliente, da de alta una Venta
 *
 * \param LinkedList* pArrayListVentas Direccion de la lista enlazada
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \return int 0 ok
 *
 */
int controller_addVentas(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes)
{
    int retorno = -1;
    int auxId,auxAfiches,zona;
    char auxNombreVideo[128];
    Ventas* ventas = Ventas_new();
    if(ventas != NULL && pArrayListVentas != NULL)
    {
    	ll_map(pArrayListClientes, returnMap);
    	if(	utn_getInt("ingrese el Id de clientes =", "ingrese correctamente el Id", &auxId, 3, 100000, 0) ==0                  &&
			idExist(pArrayListClientes, auxId)!=1                                                                               &&
			utn_getInt("ingrese La cantidad de afiches =", "ingrese correctamente la cantidad", &auxAfiches, 3, 100000, 0) ==0  &&
			utn_getAviso("ingrese el Nombre del archivo =", "ingrese correctamente el nombre", auxNombreVideo, 3, 128)==0 		&&
			utn_getInt("ingrese 0-Caba | 1-Zona sur | 2-Zona sur  =", "ingrese correctamente la zona", &zona, 3, 3, 0) ==0 )
		{
    		if(Ventas_set_idCliente(ventas, auxId)==0 &&
    		   Ventas_set_CantidadAfiches(ventas, auxAfiches) ==0 &&
			   Ventas_set_nombreArchivo(ventas, auxNombreVideo) ==0 &&
			   Ventas_set_Zona(ventas, zona) ==0 &&
			   Ventas_set_idVenta(ventas, controller_FindNextIdVentas(pArrayListVentas)) ==0 &&
    		   Ventas_set_estado(ventas, 0)==0)
    		{
    			printf("El id Creado de venta es : %d \n", controller_FindNextIdVentas(pArrayListVentas));
    			ll_add(pArrayListVentas, ventas);
    			retorno = 0;
    		}
		}else
			printf("No existe el Id que se ingreso\n");
    }
    return retorno;
}

/** \brief Modifica una venta realizada mientras el estado este sin pagar
 *
 * \param LinkedList* pArrayListVentas Direccion de la lista enlazada
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \return int 0 ok
 *
 */
int controller_ModifyVentas(LinkedList* pArrayListVentas, LinkedList* pArrayListClientes)
{
    int retorno = -1;
    int auxId,auxAfiches,zona,menu;
    char auxNombreVideo[128];
    Ventas* ventas ;
    if(pArrayListVentas != NULL && pArrayListClientes!= NULL)
    {
    	printf("id Ventas	id cliente	Cantidad de afiches 	Nombre del archivo	zona	estado\n");
		ll_map(pArrayListVentas, stateVentas);
		if(	utn_getInt("ingrese el Id de Ventas =", "ingrese correctamente el Id", &auxId, 3, 100000, 0) ==0 && idExistVentas(pArrayListVentas, auxId)==-1)
		{
			ventas = ll_get(pArrayListVentas, ll_mapAndBreak(pArrayListVentas, FindIdVentas, auxId));
			ll_mapAndBreak(pArrayListClientes, PrintById, Ventas_get_idCliente(ventas));
			utn_getInt("\n1) Cantidad de afiches \n2) Nombre del archivo\n3)Zona\n", "ingresa un numero correcto \n", &menu, 3, 3, 0);
			switch(menu)
			{
			case 1:
				if(utn_getInt("ingrese La cantidad de afiches =", "ingrese correctamente la cantidad", &auxAfiches, 3, 100000, 0) ==0)
				{
					Ventas_set_CantidadAfiches(ventas, auxAfiches);
					retorno =0;
				}
				break;

			case 2:
				if(utn_getAviso("ingrese el Nombre del archivo =", "ingrese correctamente el nombre", auxNombreVideo, 3, 128)==0)
				{
					Ventas_set_nombreArchivo(ventas, auxNombreVideo);
					retorno =0;
				}
				break;
			case 3:
				if(utn_getInt("ingrese 0-Caba | 1-Zona sur | 2-Zona sur  =", "ingrese correctamente la zona", &zona, 3, 3, 0) ==0)
				{
					Ventas_set_Zona(ventas, zona);
					retorno =0;
				}
				break;
			}
		}else
			printf("No existe el id que se ingreso\n");
    }
    return retorno;
}

/** \brief Se cobra la venta- cambia el estado a 1
 *
 * \param LinkedList* pArrayListVentas Direccion de la lista enlazada
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \return int 0 ok
 *
 */
int controller_cobrarVentas(LinkedList* pArrayListVentas, LinkedList* pArrayListClientes)
{
    int retorno = 1;
    int auxId;
    char auxConfirm;
    Ventas* ventas ;
    if(pArrayListVentas != NULL && pArrayListClientes!= NULL)
    {
    	printf("id Ventas	id cliente	Cantidad de afiches 	Nombre del archivo	zona	estado\n");
		ll_map(pArrayListVentas, stateVentas);
		if(	utn_getInt("ingrese el Id de Ventas =", "ingrese correctamente el Id", &auxId, 3, 100000, 0) ==0 && idExist(pArrayListClientes, auxId))
		{
			ventas = ll_get(pArrayListVentas, ll_mapAndBreak(pArrayListVentas, FindIdVentas, auxId));
			ll_mapAndBreak(pArrayListClientes, PrintById, Ventas_get_idCliente(ventas));
			if(utn_getChar("Desea pagar (S - N)", "Ingresa correctamente", &auxConfirm, 3)==0 && (auxConfirm == 's' || auxConfirm == 'S' ))
			{
				Ventas_set_estado(ventas, 1);
				retorno=0;
			}else
				printf("Se cancelo la modificacion \n");
		}
    }
    return retorno;
}



/** \brief Guarda en un archivo los Clientes
 *
 * \param char* path direccion donde se crea el archivo
 * \param LinkedList* pArrayListEmployee Direccion de la lista enlazada
 * \return int 0 ok
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		int len = ll_len(pArrayListEmployee);
	    Clientes* clientes = Clientes_new();
	    FILE* file;

	    if (clientes != NULL && pArrayListEmployee != NULL && len != 0 )
	    {
	    	file = fopen(path, "w");
	        fprintf(file,"id Cliente,Cuit,Nombre,Apellido\n");
	        for (int i = 0; i < len; i++)
	        {
	        	clientes = ll_get(pArrayListEmployee, i);
				fprintf(file, "%d,%s,%s,%s\n", Clientes_get_idCliente(clientes),Clientes_get_cuit(clientes), Clientes_get_nombre(clientes), Clientes_get_apellido(clientes));
				retorno = 0;
	        }
	    }
	    fclose(file);
	    return retorno;
}

/** \brief Guarda en un archivo las Ventas
 *
 *	\param char* path direccion donde se crea el archivo
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \return int 0 ok
 *
 */

int controller_saveAsTextVentas(char* path , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		int len = ll_len(pArrayListEmployee);
	    Ventas* ventas = Ventas_new();
	    FILE* file;
	    if (ventas != NULL && pArrayListEmployee != NULL && len != 0 )
	    {
	    	file = fopen(path, "w");
	        fprintf(file,"id Ventas,id cliente,Cantidad de afiches ,Nombre del archivo,zona,estado\n");
	        for (int i = 0; i < len; i++)
	        {
	        	ventas = ll_get(pArrayListEmployee, i);
				fprintf(file, "%d,%d,%d,%s,%d,%d\n", Ventas_get_idVenta(ventas),Ventas_get_idCliente(ventas),Ventas_get_CantidadAfiches(ventas),Ventas_get_nombreArchivo(ventas),Ventas_get_Zona(ventas),Ventas_get_estado(ventas));
				retorno = 0;
	        }
	    }
	    fclose(file);
	    return retorno;
}

/** \brief Guarda en un archivo los clientes con la cantidad respectivas de ventas
 *
 * \param char* path direccion donde se crea el archivo
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \param LinkedList* pArrayListVentas Direccion de la lista enlazada
 * \param int estado 1 para contar los pagados, 0 para los inactivos
 * \return int 0 ok
 *
 */

int controller_saveAsTextCobradas(char* path , LinkedList* pArrayListClientes,LinkedList* pArrayListVentas,int estado)
{
		int retorno = -1;
		int len = ll_len(pArrayListClientes);
	    Clientes* clientes = Clientes_new();
	    FILE* file;

	    if (clientes != NULL && pArrayListClientes != NULL && len != 0 )
	    {
	    	file = fopen(path, "w");
	    	fprintf(file,"id Cliente,Cuit,Nombre,Apellido,cantidad de Ventas \n");
	        for (int i = 0; i < len; i++)
	        {
	        	clientes = ll_get(pArrayListClientes, i);
	        	if(estado == 1 )
	        		fprintf(file, "%d,%s,%s,%s,%d\n", Clientes_get_idCliente(clientes),Clientes_get_cuit(clientes), Clientes_get_nombre(clientes), Clientes_get_apellido(clientes),ll_reduceIntDual(pArrayListVentas, FindCobradas, Clientes_get_idCliente(clientes)));
	        	else
	        		fprintf(file, "%d,%s,%s,%s,%d\n", Clientes_get_idCliente(clientes),Clientes_get_cuit(clientes), Clientes_get_nombre(clientes), Clientes_get_apellido(clientes),ll_reduceIntDual(pArrayListVentas, FindaCobrar, Clientes_get_idCliente(clientes)));
	        	retorno = 0;
	        }
	    }
	    fclose(file);
	    return retorno;
}


/** \brief Encuentra los usuario con mas cantidad de ventas o menos segun el estado
 *
 * \param char* path direccion donde se crea el archivo
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \param LinkedList* pArrayListVentas Direccion de la lista enlazada
 * \param int estado 1 para Max, 0 para Min
 * \return int 0 ok
 *
 */
int controller_FindMaxAndMin(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes,int estado)
{
	int varAux,auxVentas,auxId, retorno=-1;
	int len = ll_len(pArrayListClientes);
	Clientes* aux;
	if(pArrayListVentas != NULL && len >=0)
	{
		for (int i = 0 ; i< len ; i++)
		{
			aux = ll_get(pArrayListClientes, i);
			auxVentas = ll_reduceIntDual(pArrayListVentas, FindAfiches, Clientes_get_idCliente(aux));
			if(auxVentas!=0)
			{
				if((estado == 0 && (i==0 || auxVentas > varAux)) ||
				   (estado == 1 && (i==0 || auxVentas < varAux)))
				{
					varAux=auxVentas;
					auxId=Clientes_get_idCliente(aux);
				}
			}

		}
		if(estado == 0)
			printf("El cliente con mas afiches \n");
		else
			printf("El cliente con menos afiches \n");

		printf("id Cliente|Cuit             |Nombre           | Apellido\n");
		ll_mapAndBreak(pArrayListClientes, PrintById, auxId);
		printf("Cantidad de afiches fue = %d \n\n",varAux);
	}
	return retorno;
}


/** \brief Encuentra el usuarios con la cantidad de afiches vendidos
 *
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \param LinkedList* pArrayListVentas Direccion de la lista enlazada
 * \return int 0 ok
 *
 */
int controller_FindMaxAfichesVendidos(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes)
{
	int max ,auxAfiches,auxId, retorno=-1;
	int len = ll_len(pArrayListVentas);
	Ventas* aux;
	int bandera=0;
	if(pArrayListVentas != NULL && len >=0)
	{
		for (int i = 0 ; i< len ; i++)
		{
			aux = ll_get(pArrayListVentas, i);
			if( Ventas_get_estado(aux)==1)
			{
				auxAfiches = Ventas_get_CantidadAfiches(aux);
				if (bandera==0 || auxAfiches > max )
				{
					max=auxAfiches;
					auxId=i;
					bandera++;
				}
			}
		}
		aux= ll_get(pArrayListVentas, auxId);

		printf("id Cliente|Cuit             |Nombre           | Apellido\n");
		ll_mapAndBreak(pArrayListClientes, PrintById, Ventas_get_idCliente(aux));
		printf( "Cantidad de afiches que vendio =%d\n",max);
		retorno = 1;
	}
	return retorno;
}


/** \brief Encuentra el Id de un cliente en una linked list
 *
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \param int idUser el id a comparar
 * \return indice de la linkedList
 *
 */

int controller_FindId(LinkedList* pArrayListEmployee,int idUser)
{
	Clientes* clientes = NULL;
	int len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee !=NULL && idUser >0)
	{
		for(int i = 0; i < len; i++ )
		{
			clientes = ll_get(pArrayListEmployee, i);
			if( idUser == Clientes_get_idCliente(clientes))
			{
				return i;
			}
		}
	}
	return -1;
}


/** \brief Encuentra el next Id una linkedList Cliente
 *
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \return el sigueinte id, si no encuentra ningun usuario devuelve 1
 *
 */

int controller_FindNextIdClientes(LinkedList* pArrayListEmployee)
{
	int max ;
	int retorno=1;
	int auxId;
	Clientes* aux;
	int len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && len >=0)
	{
		for (int i = 0 ; i< len ; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			auxId = Clientes_get_idCliente(aux);
			if (i==0 || auxId > max )
			{
				max=auxId;
			}
		}
		retorno=max+1;
	}
	return retorno;
}

/** \brief Encuentra el next Id una linkedList Ventas
 *
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \return el sigueinte id, si no encuentra ningun usuario devuelve 1
 *
 */

int controller_FindNextIdVentas(LinkedList* pArrayListEmployee)
{
	int max ;
	int retorno=1;
	int auxId;
	int len = ll_len(pArrayListEmployee);
	Ventas* aux;
	if(pArrayListEmployee != NULL && len >=0)
	{
	for (int i = 0 ; i< len ; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			auxId = Ventas_get_idVenta(aux);
			if (i==0 || auxId > max )
			{
				max=auxId;
			}
		}
		retorno=max+1;
	}
	return retorno;
}


/** \brief Se fija ssi existe el cuit el la linkedList
 *
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \return el sigueinte id, si no encuentra ningun usuario devuelve 1
 *
 */

int cuitRepetido(LinkedList* pArrayListEmployee, char* cuit)
{
	int retorno = 1;
	int len = ll_len(pArrayListEmployee);
	Clientes* aux;
	if(pArrayListEmployee != NULL && len >=0)
	{
		for (int i = 0 ; i< len ; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			if (strcmp(Clientes_get_cuit(aux),cuit)==0)
			{
				retorno =-1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Se fija si existe el Id del Cliente el la linkedList
 *
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \return el sigueinte id, si no encuentra ningun usuario devuelve 1
 *
 */
int idExist(LinkedList* pArrayListEmployee, int id)
{
	int retorno = 1;
	int len = ll_len(pArrayListEmployee);
	Clientes* aux;
	if(pArrayListEmployee != NULL && len >=0)
	{
		for (int i = 0 ; i< len ; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			if (Clientes_get_idCliente(aux) == id)
			{
				retorno =-1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Se fija si existe el Id del Ventas el la linkedList
 *
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \return el sigueinte id, si no encuentra ningun usuario devuelve 1
 *
 */

int idExistVentas(LinkedList* pArrayListEmployee, int id)
{
	int retorno = 1;
	int len = ll_len(pArrayListEmployee);
	Ventas* aux;
	if(pArrayListEmployee != NULL && len >=0)
	{
		for (int i = 0 ; i< len ; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			if (Ventas_get_idVenta(aux) == id && Ventas_get_estado(aux) == 0)
			{
				retorno =-1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief agrega csv a un sting
 *
 * \param LinkedList* pArrayListClientes Direccion de la lista enlazada
 * \return el string mandando + un csv
 */

char* agregarCsv(char* aux)
{
	char csv[]=".csv";
	strcat(aux,csv);
	return aux;
}
