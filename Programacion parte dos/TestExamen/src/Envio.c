#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "Envio.h"


/** \brief free the memory direction
 *
 * \param Envio* this memory direction of the linked list
 *
 */

void envio_delete(Envio* this)
{
	free(this);
}


/** \brief free the memory direction
 *
 * \return Envio*  memory direction of new employee
 *
 */
Envio* envio_new()
{
	return (Envio*)malloc(sizeof(Envio));
}


/** \brief add all the params to the employee
 *
 * \param char* idStr  the Id of the new employee
 * \param char* nombreStr the name of the new employee
 * \param char* char* horasTrabajadasStr the working hours of the new employee
 * \param char* sueldoStr the salary of the new employee
 * \return Envio*
 *
 */

Envio* envio_newParametros(char* idEnvio,char* nombre,char* idCamion,char* zona,char* km, char* entrega)
{
	Envio* pEnvio = envio_new();
	if(pEnvio!=NULL)
	{
		if(envio_allSet(pEnvio, nombre, zona, atoi(km), atoi(idCamion), atoi(idEnvio), atoi(entrega), 0)==0)
		{
			return pEnvio;
		}
	}
	else{printf("Error - No quedan libres"); }
		return NULL;
}


//******************************************

/** \brief set the id in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int id the Id of the new employee
 * \return int return 0 - ok -1 - error
 *
 */
int envio_setIdProducto(Envio* this,int id)
{
	if(this != NULL && id>0)
	{
		this->idProducto = id;
		return  0;
	}
	return  -1;
}


/** \brief get the id in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int id the Id of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_getIdProducto(Envio* this,int* id)
{	if(this != NULL)
	{
		*id =this->idProducto;
		return 0;
	}
	else
		return -1;
}

//******************************************

/** \brief set the id in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int id the Id of the new employee
 * \return int return 0 - ok -1 - error
 *
 */
int envio_setIdCamion(Envio* this,int id)
{
	if(this != NULL && id>0)
	{
		this->idCamion = id;
		return  0;
	}
	return  -1;
}


/** \brief get the id in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int id the Id of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_getIdCamion(Envio* this,int* id)
{	if(this != NULL)
	{
		*id =this->idCamion;
		return 0;
	}
	else
		return -1;
}

//******************************************

/** \brief set the working hour in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int horasTrabajadas the working hour of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */

int envio_setKm(Envio* this,int km)
{
	if(this != NULL && (km>=0 && km < 999999))
	{
		this->km = km;
		return 0;
	}
	return -1;
}


/** \brief set the working hour in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int horasTrabajadas the working hour of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_getKm(Envio* this,int* km)
{	if(this != NULL)
	{
		*km = this->km;
		return 0;
	}
	else
		return -1;
}

//******************************************

/** \brief set the salary in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int salary the salary of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_setTipoDeEntrega(Envio* this,int tipoDeEntrega)
{
	int retorno = -1;
	if(this != NULL && (tipoDeEntrega >=0 && tipoDeEntrega <= 3))
	{
		this->tipoDeEntrega = tipoDeEntrega;
		retorno = 0;
	}
	return retorno;
}


/** \brief set the salary in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int salary the salary of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_getTipoDeEntrega(Envio* this,int* tipoDeEntrega)
{	if(this != NULL)
	{
		*tipoDeEntrega =this->tipoDeEntrega;
		return 0 ;
	}
	else
		return -1;
}

/** \brief set the salary in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int salary the salary of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_setCosto(Envio* this,int costo)
{
	int retorno = -1;
	if(this != NULL && (costo >=0 && costo <= 99999))
	{
		this->costo = costo;
		retorno = 0;
	}
	return retorno;
}


/** \brief set the salary in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int salary the salary of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_getCosto(Envio* this,int* costo)
{	if(this != NULL)
	{
		*costo =this->costo;
		return 0 ;
	}
	else
		return -1;
}

//*****************************************************

/** \brief set the name in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int nombre the name of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_setNombre(Envio* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && envio_validName(nombre,(int)sizeof(nombre)))
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno=0;
	}
	return retorno;
}


/** \brief set the name in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int id the Id of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_getNombre(Envio* this,char* nombre)
{	if(this != NULL)
	{
		strncpy(nombre, this->nombre,(int)sizeof(this->nombre));
		return 0;
	}
	else
		return -1;
}

int envio_setZona(Envio* this,char* zona)
{
	int retorno = -1;
	if(this != NULL && envio_validName(zona,(int)sizeof(zona)))
	{
		strncpy(this->zona,zona,sizeof(this->zona));
		retorno=0;
	}
	return retorno;
}


/** \brief set the name in the employee
 *
 * \param Envio* the memory direction of the employee
 * \param int id the Id of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_getZona(Envio* this,char* zona)
{	if(this != NULL)
	{
		strncpy(zona, this->zona,(int)sizeof(this->zona));
		return 0;
	}
	else
		return -1;
}

/** \brief return the id in the employee
 *
 * \return int  return a new Id
 *
 */
int envio_generarNuevoId(void)
{
    static int id = 0;
    id = id+1;
    return id;
}



/** \brief string send to valid the name
 *
 * \param char* cadena string with a name
 * \param int limite len of the string
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_validName(char* cadena,int limite)
{
	int respuesta = -1;

	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		//esta mal <----- A - Z -----> Esta mal
		if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z') &&
			 cadena[i] != '.')
		{
			respuesta = 1;
			break;
		}
	}
	return respuesta;
}


/** \brief add all the params to the employee
 *
 * \param Envio* the memory direction of the employee
 * \param char* idStr  the Id of the new employee
 * \param char* nombreStr the name of the new employee
 * \param char* char* horasTrabajadasStr the working hours of the new employee
 * \param char* sueldoStr the salary of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */
int envio_allSet(Envio* this,char* nombre,char* zona ,int km,int IdCamion, int IdProducto,int TipoDeEntrega,int costo)
{
	if (this!=NULL)
	{
		envio_setIdProducto(this,IdProducto);
		envio_setIdCamion(this,IdCamion);
		envio_setKm(this, km);
		envio_setTipoDeEntrega(this, TipoDeEntrega);
		envio_setCosto(this, costo);
		envio_setNombre(this, nombre);
		envio_setZona(this, zona);
		return 0;
	}
	return -1;
}


/** \brief add all the params to the employee
 * \param Envio* the memory direction of the employee
 * \param char* idStr  the Id of the new employee
 * \param char* nombreStr the name of the new employee
 * \param char* char* horasTrabajadasStr the working hours of the new employee
 * \param char* sueldoStr the salary of the new employee
 * \return int  return 0 - ok -1 - error
 *
 */


int envio_allGet(Envio* this,char* nombre,char* zona ,int* km,int* IdCamion, int* IdProducto,int* TipoDeEntrega,int* costo)
{
	if(this!=NULL)
	{
		envio_getIdProducto(this,IdProducto);
		envio_getIdCamion(this,IdCamion);
		envio_getKm(this, km);
		envio_getTipoDeEntrega(this, TipoDeEntrega);
		envio_getCosto(this, costo);
		envio_getNombre(this, nombre);
		envio_getZona(this, zona);
			return 0;
	}
	return -1;

}

//funciones de Criterio

int calcularCostos(void* pElemnto)
{
	int retorno = -1;
	Envio* envio = (Envio*)pElemnto;
	int km,tipoDeEntrega,valorKm,valorEntrega, total;

	envio_getKm(envio, &km);
	envio_getTipoDeEntrega(envio, &tipoDeEntrega);
	if(km<50)
		valorKm=150;
	else
		valorKm=100;

	if(tipoDeEntrega==0)
		valorEntrega=350;
	else if(tipoDeEntrega==1)
		valorEntrega=420;
	else
		valorEntrega=275;
	total = ((km*valorKm) + valorEntrega);
	envio_setCosto(envio, total);
	retorno = 0;

	return retorno;
}
/*
int returnMap(void* pElemnto)
{
	int retorno = 0;
	Envio* empleado = (Envio*)pElemnto;
	int auxSueldo;
	if(1)
	{
		retorno = 1;
	}
	return retorno;
}

int returnNameMap(void* pElemnto)
{
	int retorno = 0;
	Envio* empleado = (Envio*)pElemnto;
	char auxName[148];
	if((envio_getNombre(empleado, auxName)==0) &&  auxName[0] == 'A')
	{
		retorno = 1;
	}
	return retorno;
}
//if((envio_getNombre(empleado, auxName)==0) && auxName[0] == 'A')  strcmp(auxName,"Josiah")==0

float returnSueldoMap(void* pElemnto)
{
	float retorno = 0;
	//Envio* empleado = (Envio*)pElemnto;
	//int auxSueldo;
	//if(envio_getSueldo(empleado, &auxSueldo)==0)
	//{
		//retorno = auxSueldo;
	//}
	return retorno;
}


*/


int returnZonaMap(void* pElemnto,char* zona)
{
	int retorno = 0;
	Envio* envio = (Envio*)pElemnto;
	char auxName[148];

	if((envio_getZona(envio, auxName)==0) &&  (strcmp(auxName,zona)==0))
	{
		retorno = 1;
	}
	return retorno;
}





Zona* zona_new()
{
	return (Zona*)malloc(sizeof(Zona));
}


int zona_getZona(Zona* this,char* zona)
{	if(this != NULL)
	{
		strncpy(zona, this->zona,(int)sizeof(this->zona));
		return 0;
	}
	else
		return -1;
}

int zona_setZona(Zona* this,char* zona)
{
	int retorno = -1;
	if(this != NULL && envio_validName(zona,(int)sizeof(zona)))
	{
		strncpy(this->zona,zona,sizeof(this->zona));
		retorno=0;
	}
	return retorno;
}


Zona* zona_newParam(char* nombre)
{
    Zona* this = zona_new();

    if(this != NULL && nombre != NULL && zona_setZona(this, nombre) == 0)
    {
        return this;
    }
    return this;
}





int sortZona(void* this1, void* this2)
{
    int retorno = 0;
    Envio* auxEmp1 = (Envio*)this1;
    Envio* auxEmp2 = (Envio*)this2;
    char bufferNombre1[148];
    char bufferNombre2[148];

    if(this1 != NULL && this2 != NULL &&
      (envio_getZona(auxEmp1, bufferNombre1)==0) && (envio_getZona(auxEmp2, bufferNombre2)==0))
    {
        if(strcmp(bufferNombre1,bufferNombre2) < 0)
        {
            retorno = 1;
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}











