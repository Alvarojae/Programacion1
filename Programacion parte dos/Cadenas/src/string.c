#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"
static int myGets (char *cadena, int longitud);

int getNombre(char* mensaje, char* mensajeError, char* pResultado, int reintentos, int limite)
{
	int retorno = -1;
	char bufferString[900000];
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%s",bufferString);

			if(resultadoScanf == 1 &&
			   strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
			   esNombre(bufferString,limite)!=0)


			{
				retorno = 0;
				strcpy(pResultado,bufferString);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}


int esNombre (char *cadena,int limite)
{
	int respuesta = 1;
	for(int i ;i<= limite && cadena[i] != '\0';i++)
	{
		if( (cadena[i]< 'A' || cadena[i] > 'Z') &&
		    (cadena[i]< 'a' || cadena[i] > 'z') &&
			(cadena[i] != ' '                 ) )
		{
			respuesta = 0;
			break;
		}
	}

	return respuesta;
}



static int myGets (char *cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1]= '\n';
	return 0;

}











