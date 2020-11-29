#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Ventas.h"
#include "Clientes.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEnvio LinkedList* direccion de la Linked list
 * \return int
 *
 */
int parser_EnvioFromText(FILE* pFile , LinkedList* pArrayListEnvio)
{
	int retorno=-1;
	int var;
	char buffer[6][2500];
	if (pFile != NULL )
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
		while( !feof(pFile) )
		{
			var = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
			if ( var == 6 )
			{
				Ventas* auxEmp = Ventas_new();
				if(auxEmp != NULL)
				{
					auxEmp = Ventas_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
					ll_add(pArrayListEnvio, auxEmp);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEnvio LinkedList* direccion de la Linked list
 * \return int
 */
int parser_EnvioFromTextDos(FILE* pFile , LinkedList* pArrayListEnvio)
{
	int retorno=-1;
	int var;
	char buffer[4][2500];
	if (pFile != NULL )
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2],buffer[3]);
		while( !feof(pFile) )
		{
			var = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2],buffer[3]);
			if ( var == 4 )
			{
				Clientes* auxEmp = Clientes_new();
				if(auxEmp != NULL)
				{
					auxEmp = Clientes_newParametros(buffer[0], buffer[1], buffer[2],buffer[3]);
					ll_add(pArrayListEnvio, auxEmp);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
