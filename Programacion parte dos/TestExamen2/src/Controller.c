#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Post.h"
#include "usuario.h"
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

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */

		//	printf(" %04d | %-15s | %-4d | %-15s | %-4d | %-4d| %-4d\n", auxIdEnvio,auxNombre ,auxIdCamion,auxZona,km, TipoDeEntrega, costo);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListUser,LinkedList* pArrayListPost)
{
	int retorno = -1;
	int idUsuario;
	int indiceMensaje;
	int len = ll_len(pArrayListUser);
	FILE* file;
	Usuario* aux;
	Post* auxPost;
	file = fopen(path, "w");
	fprintf(file,"Id Usuario , nick , Popularidad de usuario , id Mensaje , popularidad mensaje , Mensaje\n");
	for(int i =0; i<len;i++)
	{
	   aux= ll_get(pArrayListUser, i);
	   idUsuario = Usuario_get_id_usuario(aux);
	   indiceMensaje = ll_mapAndBreak(pArrayListPost, returnIndice, idUsuario);
	   if(indiceMensaje != -1 )
	   {
		   auxPost=ll_get(pArrayListPost, indiceMensaje);
		   fprintf(file, "%d,%s,%d,%d,%d,%s\n", Usuario_get_id_usuario(aux),Usuario_get_nick(aux) ,Usuario_get_popularidad(aux),Post_get_id_mensaje(auxPost),Post_get_popularidad(auxPost), Post_get_mensaje(auxPost));
		   retorno = 0;
	   }
	}
	fclose(file);
	return retorno;
}

int returnIndice(void* pElemnto,int indice)
{
	int retorno = 0;
	Post* envio = (Post*)pElemnto;
	int idUsuario = Post_get_id_usuario(envio);

	if( idUsuario == indice)
	{
		retorno = 1;
	}
	return retorno;
}


char* agregarCsv(char* zona)
{
	char csv[]=".csv";
	strcat(zona,csv);
	return zona;
}



