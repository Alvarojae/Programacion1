#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Envio.h"
#include "parser.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_EnvioFromText(FILE* pFile , LinkedList* pArrayListEnvio)
{

	int retorno=-1;
	int var;
	char buffer[6][20];
	if (pFile != NULL )
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
		while( !feof(pFile) )
		{
			var = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
			if ( var == 6 )
			{
				Envio* auxEmp = envio_new();
				if(auxEmp != NULL)
				{
					auxEmp = envio_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
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
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 */
int parser_EnvioFromBinary(FILE* pFile , LinkedList* pArrayListEnvio)
{
	int retorno = -1;
	int var;
	if (pFile != NULL && pArrayListEnvio != NULL)
	{
		while( !feof(pFile) )
		{
			Envio* auxEmp = envio_new();
			if (auxEmp != NULL)
			{
				var = fread(auxEmp,sizeof(Envio),1,pFile);
				if ( var == 1 )
				{
					ll_add(pArrayListEnvio, auxEmp);
				}
				retorno = 0;
			}
		}
	}
	return retorno;
}
