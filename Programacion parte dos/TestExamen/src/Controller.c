#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Envio.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
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
int controller_loadFromBinary(char* path , LinkedList* pArrayListEnvio)
{
	int retorno = -1;
	FILE* file;
	if(path != NULL && pArrayListEnvio !=NULL)
	{
		file = fopen(path, "rb");

		if(parser_EnvioFromBinary(file,pArrayListEnvio)==0)
		{
			retorno =0;
		}else
		{
			//file = fopen(path, "wb");
			printf("No existia el archivo y fue creado\n");
			retorno = 0;
		}
	}
	fclose(file);
    return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int controller_ListEnvio(LinkedList* pArrayListEnvio)
{
	int retorno = -1;
	int km;
	int auxIdCamion;
	int auxIdEnvio;
	int TipoDeEntrega;
	int costo;
	char auxNombre[128];
	char auxZona[128];

	int len = ll_len(pArrayListEnvio);
	Envio* envio = envio_new();
	if ( envio != NULL && len != 0)
	{
		printf("\nid_envio - nombre_producto - id_camion - zona_destino - km_recorridos - tipo_entrega\n");
		for (int i = 0; i < len; i++)
		{
			envio = ll_get(pArrayListEnvio, i);
			envio_allGet(envio, auxNombre, auxZona, &km, &auxIdCamion, &auxIdEnvio, &TipoDeEntrega, &costo);
			printf(" %04d | %-15s | %-4d | %-15s | %-4d | %-4d| %-4d\n", auxIdEnvio,auxNombre ,auxIdCamion,auxZona,km, TipoDeEntrega, costo);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int controller_sortEnvio(LinkedList* pArrayListEnvio)
{
	int retorno = -1;
	int len = ll_len(pArrayListEnvio);
	char auxNombre[128];
	char auxNombre1[128];
	Envio* empleado = envio_new();
	Envio* empleadoAux = envio_new();

	printf("\nSe estan ordenando\n");
	if ( empleado != NULL && empleadoAux != NULL && len != 0)
	{
		for (int i = 0; i < len; i++)
		{
			for ( int j = i + 1; j < len; j++)
			{
				empleado = ll_get(pArrayListEnvio, i);
				empleadoAux = ll_get(pArrayListEnvio, j);
				envio_getNombre(empleado, auxNombre);
				envio_getNombre(empleadoAux, auxNombre1);
				if ( strcmp(auxNombre, auxNombre1) > 0 )
				{
					ll_set(pArrayListEnvio,j, empleado);
					ll_set(pArrayListEnvio,i, empleadoAux);
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEnvio)
{
		int retorno = -1;
		int auxIdCamion;
		int auxIdEnvio;
		int costo;
		int km;
		int TipoDeEntrega;
		char auxNombre[128];
		char auxZona[128];
		int len = ll_len(pArrayListEnvio);
	    Envio* envio = envio_new();
	    FILE* file;

	    if (envio != NULL && pArrayListEnvio != NULL && len != 0 )
	    {
	    	file = fopen(path, "w");
	        fprintf(file,"id_envio ,nombre_producto,id_camion,zona_destino,km_recorridos,tipo_entrega\n");
	        for (int i = 0; i < len; i++)
	        {
	        	envio = ll_get(pArrayListEnvio, i);
	            if(envio_allGet(envio, auxNombre, auxZona, &km, &auxIdCamion, &auxIdEnvio, &TipoDeEntrega, &costo)==0)
	            {
					fprintf(file, "%d,%s,%d,%s,%d,%d,%d\n", auxIdEnvio,auxNombre ,auxIdCamion,auxZona,km, TipoDeEntrega,costo);
					retorno = 0;
	            }
	        }
	    }
	    fclose(file);
	    return retorno;
}


LinkedList* controller_zonas(LinkedList* pArrayListEnvio)
{
	LinkedList* listaZonas=NULL;
	char pResultado[148];
	if(pArrayListEnvio!=NULL)
	{
		generarListaZona(pArrayListEnvio);
		utn_getNombre("ingrese una zona para crear el archivo= ", "ingrese un nombre correcto", pResultado, 3, 148);
		listaZonas = ll_filterAndAdd(pArrayListEnvio, returnZonaMap ,pResultado);
		controller_saveAsText(agregarCsv(pResultado), listaZonas);
	}
	return listaZonas;
}




LinkedList* generarListaZona(LinkedList* listaEnvios)
{
	LinkedList* listaOrdenada,* listaZonas = NULL ;
	if(listaEnvios!=NULL)
	{
		listaOrdenada = ll_clone(listaEnvios);
		ll_sort(listaOrdenada, sortZona, 0);
		//controller_saveAsText("listaOrdenada", listaOrdenada);
		//controller_ListEnvio(listaOrdenada);
		listaZonas =ll_newLinkedList();
		int len = ll_len(listaOrdenada)-1;
		Zona* zonaAux;
		Envio* auxA,*auxB;
		char auxCharA[148],auxCharB[148];
		for(int i = 0 ; i<len  ;i++ )
		{
			auxA=ll_get(listaOrdenada, i);
			auxB=ll_get(listaOrdenada, i+1);
			envio_getZona(auxA, auxCharA);
			envio_getZona(auxB, auxCharB);

			if(i == len-1 || strcmp(auxCharA,auxCharB)!=0)
			{
				zonaAux = zona_new();
				zona_setZona(zonaAux, auxCharA);
				ll_add(listaZonas, zonaAux);
			}
		}
		printTest(listaZonas);
	}
	return listaZonas;
}

void printTest(LinkedList* test)
{
	char aux[148];
	for(int i = 0 ; i<ll_len(test);i++)
	{
		zona_getZona(ll_get(test, i), aux);
		printf("%s\n",aux);
	}

}



int controller_zonasNoRepetidas(LinkedList* pArrayListEnvio)
{
	int retorno = -1 ;
	if(pArrayListEnvio!=NULL)
	{
			LinkedList* auxSort,* listaOrdenada = ll_newLinkedList();
			auxSort = ll_clone(pArrayListEnvio);
			char zona[148],zona2[148];
			int aux,i,j;
			Envio* envio = envio_new();
			Zona* zonaAux ;

			for(i=0;i<ll_len(auxSort);i++)
			{
				envio=ll_get(auxSort, i);
				envio_getZona(envio, zona);
				aux=0;
				if(i==0)
				{
					zonaAux = zona_new();
					zona_setZona(zonaAux, zona);
					ll_add(listaOrdenada, zonaAux);
				}
				for(j=0;j<ll_len(listaOrdenada);j++)
				{
					zonaAux=ll_get(listaOrdenada, j);
					zona_getZona(zonaAux, zona2);
					if(strcmp(zona,zona2)==0)
					{
						aux++;
						break;
					}
				}
				if(aux==0)
				{
					zonaAux = zona_new();
					zona_setZona(zonaAux, zona);
					ll_add(listaOrdenada, zonaAux);
				}
			}
			printTest(listaOrdenada);
	}
	return retorno;
}

/*
void zona_imprimir(LinkedList* pArrayEnvio)
{
    LinkedList* listaZonas = ll_newLinkedList();
    char nombre[148];
    Zona* auxZona;

    if(pArrayEnvio != NULL)
    {
        zona_generarLista(listaZonas, pArrayEnvio);

        for (int i = 0; i < ll_len(listaZonas); i++)
        {
            auxZona = ll_get(listaZonas, i);
            if(zona_getZona(auxZona, nombre) == 0)
            {
                printf("%s\n",nombre);
            }
        }
    }
}

void zona_generarLista(LinkedList* pArrayZona, LinkedList* pArrayEnvio)
{
    char zona[148];
    Zona* zonaAux;
    if(pArrayZona != NULL && pArrayEnvio != NULL)
    {
        for (int i = 0; i < ll_len(pArrayEnvio); i++)
        {
            envio_getZona(ll_get(pArrayEnvio, i), zona);
            if(zona_estaEnMiLista(pArrayZona, zona) != 1)
            {
            	zonaAux = zona_new();
            	zona_setZona(zonaAux, zona);
                ll_add(pArrayZona, zonaAux);
            }
        }
    }
}

int zona_estaEnMiLista(LinkedList* pArrayZona, char* zonaNombre)
{
    int retorno = 0;
    Zona* auxZona;
    char nombreZona[148];

    if(pArrayZona != NULL && zonaNombre != NULL)
    {
        for (int i = 0;  i < ll_len(pArrayZona); i++)
        {
            auxZona = ll_get(pArrayZona, i);
            zona_getZona(auxZona, nombreZona);
            if(strncmp(nombreZona,zonaNombre,148) == 0)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}



*/

/*
 * int controller_zonasNoRepetidas(LinkedList* pArrayListEnvio)
{
	int retorno = -1 ;
	char zona[148];
	char Zonas[15][148];
	int aux,aux1=0,i,j;
	Envio* envio = envio_new();
	for(j=0;j<15;j++)
		Zonas[j][0]='0';

	for(i=0;i<ll_len(pArrayListEnvio);i++)
	{
		envio=ll_get(pArrayListEnvio, i);
		envio_getZona(envio, zona);
		aux=0;
		for(j=0;j<15;j++)
		{
			if(strcmp(zona,Zonas[j])==0)
			{
				aux++;
			}
		}
		if(aux==0)
		{
			strcpy(Zonas[aux1],zona);
			aux1++;
		}
	}

	printf("Zonas =\n");
	for(int j=0;j<15;j++)
	{
		if(Zonas[j][0]!='0')
			printf("%s\n",Zonas[j]);
	}
	return retorno;
}
 *
 */


char* agregarCsv(char* zona)
{
	char csv[]=".csv";
	strcat(zona,csv);
	return zona;
}



