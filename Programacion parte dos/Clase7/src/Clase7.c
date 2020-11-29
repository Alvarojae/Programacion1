#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
int mostrarArrayInt(int pArray[], int limite);
int contarArray(int pArray[], int limite,int numero,int *resultadoDe7);
int contarChar(char pArray[],char letra,int *resultadoDeE);
int esSoloLetras(char Array[]);
int main(void) {
	setbuf(stdout, NULL);
	int resultadoDe7;
	int resultadoDeE;
	int numeros[12]={3,7,4,5,2,3,7,1,7,3,2,7};
	char nombre[8]={'p','e','p','e','1','2','3','\0'};
	char texto[100];

	fflush(stdin);
	printf("Ingrese un Texto (Solo letras)= ");
	scanf("%s",texto);

	mostrarArrayInt(numeros,12);
	if(contarArray(numeros,12,7,&resultadoDe7)==0)
	{
		printf("\nla cantidad de 7 en el array es = %d",resultadoDe7);
	}else
	{
		printf("Hubo algun error");
	}

	if(contarChar(nombre,'e',&resultadoDeE)==0)
	{
		printf("\nla cantidad de 'e' en el array es = %d",resultadoDeE);
	}else
	{
		printf("\nHubo algun error");
	}

	if(esSoloLetras(texto)==0)
		{
			printf("\nel array son todas letras");
		}else
		{
			printf("\nEl array contiene algo que no son letras");
		}
	return EXIT_SUCCESS;



}


int mostrarArrayInt(int pArray[], int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i = 0 ;i<limite;i++)
		{
			printf("\nel numero del indice %d es = %d",i,pArray[i]);

		}
		retorno=0;
	}
	return retorno;
}

int contarArray(int pArray[], int limite,int numero,int *resultadoDe7)
{
	int retorno = -1;
	int i;
	int cantidadDeNum=0;
	if(pArray != NULL && limite > 0 && resultadoDe7 != NULL)
	{
		for(i = 0 ;i<limite;i++)
		{
			if(pArray[i]==numero)
			{
				cantidadDeNum++;
			}

		}
		retorno=0;
		*resultadoDe7=cantidadDeNum;
	}

	return retorno;
}


int contarChar(char pArray[],char letra,int *resultadoDeE)
{
	int retorno = -1;
	int i=0;
	int cantidadDeLetras=0;

	if(pArray != NULL && resultadoDeE != NULL)
	{
		while(pArray[i] != '\0')
		{
			if(pArray[i] == letra)
			{
				cantidadDeLetras++;
			}
			i++;
		}
		retorno=0;
		*resultadoDeE=cantidadDeLetras;
	}

	return retorno;
}

int esSoloLetras(char Array[])
{
	int respuesta = 0;
	int i=0;
	if(Array != NULL)
	{
		while(Array[i] != '\0')
		{
			if((Array[i] < 'a' || Array[i] > 'z')
					           &&
			   (Array[i] < 'A' || Array[i] > 'Z'))
			{
				respuesta = -1;
				break;
			}
			i++;
		}
	}
	return respuesta;
}


/*
5) Hacer una funcion que reciba el array del punto 4, y verifique que las
 letras dentro del mismo esten en el rango de 'a' a 'z' o de 'A' a 'Z'. Si
  estan dentro del rango la funcion deberá devolver por valor(usando el return)
   un 0, de lo contrario devolverá -1.


 */
