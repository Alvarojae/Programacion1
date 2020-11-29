#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Post.h"
#include "parser.h"
#include "usuario.h"


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
	char buffer[4][2500];
	if (pFile != NULL )
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3]);
		while( !feof(pFile) )
		{
			var = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2], buffer[3]);
			if ( var == 4 )
			{
				Post* auxEmp = Post_new();
				if(auxEmp != NULL)
				{
					auxEmp = Post_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
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
int parser_EnvioFromTextDos(FILE* pFile , LinkedList* pArrayListEnvio)
{

	int retorno=-1;
	int var;
	char buffer[3][2500];
	if (pFile != NULL )
	{
		fscanf(pFile, "%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2]);
		while( !feof(pFile) )
		{
			var = fscanf(pFile, "%[^,],%[^,],%[^\n]", buffer[0], buffer[1], buffer[2]);
			if ( var == 3 )
			{
				Usuario* auxEmp = Usuario_new();
				if(auxEmp != NULL)
				{
					auxEmp = Usuario_newParametros(buffer[0], buffer[1], buffer[2]);
					ll_add(pArrayListEnvio, auxEmp);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
