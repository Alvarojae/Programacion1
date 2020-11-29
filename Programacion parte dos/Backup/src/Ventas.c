#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ventas.h"
#include <conio.h>
#include <ctype.h>
//#include "Clientes.h"

/** \brief create the new Ventas
 *
 * \return Employee*  memory direction of new Ventas
 *
 */
Ventas* Ventas_new()
{   Ventas* new =(Ventas*)malloc(sizeof(Ventas));
    return new;
}


/** \brief add all the params to the Ventas
 *
 * \param char* idVenta  the idVenta of the new Ventas
 * \param char* idCliente the id Cliente of the new Ventas
 * \param char* char* CantidadAfiches the Cantidad de Afiches of the new Ventas
 * \param char* nombreArchivo the nombre del Archivo of the new Ventas
 * \param char* Zona the Zona of the new Ventas
 * \param char* estado the estado of the new Ventas
 * \return Employee*
 *
 */
Ventas* Ventas_newParametros(char* idVenta,char* idCliente ,char* CantidadAfiches,char* nombreArchivo,char* Zona, char* estado)
{
    Ventas* this = Ventas_new();
    if(this != NULL)
    {
	   if( Ventas_set_idVenta(this,atoi(idVenta)) != -1 &&
		   Ventas_set_estado(this,atoi(estado)) != -1 &&
		   Ventas_set_nombreArchivo(this,nombreArchivo) != -1 &&
	       Ventas_set_idCliente(this,atoi(idCliente)) != -1 &&
	       Ventas_set_CantidadAfiches(this,atoi(CantidadAfiches)) != -1 &&
		   Ventas_set_Zona(this,atoi(Zona)) != -1 )
	   {
               return this;
	   }
    }
    return NULL;
}

/** \brief free the memory direction
 *
 * \return Employee*  memory direction of new Ventas
 *
 */
void Ventas_delete(Ventas* this)
{
	free(this);
}

/** \brief set the name in the Clientes
 *
 * \param Clientes* the memory direction of the Clientes
 * \param char* nombre the name of the new Clientes
 * \return int return 0 - ok -1 - error
 *
 */
int Ventas_set_nombreArchivo(Ventas* this, char* nombreArchivo)
{
	int retorno=-1;
	if(this!=NULL)
	{
            strncpy(this->nombreArchivo,nombreArchivo,(int)sizeof(this->nombreArchivo));
	    retorno=0;
	}
	return retorno;
}

/** \brief get the apellido in the Clientes
 *
 * \param Clientes* the memory direction of the Clientes
 * \return get the apellido -error NULL
 *
 */
 char* Ventas_get_nombreArchivo(Ventas* this)
{
	if(this!=NULL )
	{
	    return this->nombreArchivo;
	}else
            return NULL;
}

 /** \brief set the name in the Clientes
  *
  * \param Clientes* the memory direction of the Clientes
  * \param char* nombre the name of the new Clientes
  * \return int return 0 - ok -1 - error
  *
  */
int Ventas_set_idCliente(Ventas* this, int idCliente)
{
	int retorno=-1;
	if(this!=NULL )
	{
            this->idCliente=idCliente;
	    retorno=0;
	}
	return retorno;
}

/** \brief get the apellido in the Clientes
 *
 * \param Clientes* the memory direction of the Clientes
 * \return get the apellido -error NULL
 *
 */
 int Ventas_get_idCliente(Ventas* this)
{
	if(this!=NULL )
	{
	    return this->idCliente;
	}else
            return -1;
}

 /** \brief set the name in the Clientes
  *
  * \param Clientes* the memory direction of the Clientes
  * \param char* nombre the name of the new Clientes
  * \return int return 0 - ok -1 - error
  *
  */
int Ventas_set_CantidadAfiches(Ventas* this, int CantidadAfiches)
{
	int retorno=-1;
	if(this!=NULL )
	{
            this->CantidadAfiches=CantidadAfiches;
	    retorno=0;
	}
	return retorno;
}

/** \brief get the apellido in the Clientes
 *
 * \param Clientes* the memory direction of the Clientes
 * \return get the apellido -error NULL
 *
 */
 int Ventas_get_CantidadAfiches(Ventas* this)
{
	if(this!=NULL )
	{
	    return this->CantidadAfiches;
	}else
            return -1;
}

 /** \brief set the name in the Clientes
  *
  * \param Clientes* the memory direction of the Clientes
  * \param char* nombre the name of the new Clientes
  * \return int return 0 - ok -1 - error
  *
  */
int Ventas_set_Zona(Ventas* this, int Zona)
{
	int retorno=-1;
	if(this!=NULL )
	{
            this->Zona=Zona;
	    retorno=0;
	}
	return retorno;
}

/** \brief get the apellido in the Clientes
 *
 * \param Clientes* the memory direction of the Clientes
 * \return get the apellido -error NULL
 *
 */
 int Ventas_get_Zona(Ventas* this)
{
	if(this!=NULL )
	{
	    return this->Zona;
	}else
            return -1;
}


 /** \brief set the name in the Clientes
  *
  * \param Clientes* the memory direction of the Clientes
  * \param char* nombre the name of the new Clientes
  * \return int return 0 - ok -1 - error
  *
  */
 int Ventas_set_idVenta(Ventas* this, int idVenta)
 {
 	int retorno=-1;
 	if(this!=NULL )
 	{
             this->idVenta=idVenta;
 	    retorno=0;
 	}
 	return retorno;
 }

 /** \brief get the apellido in the Clientes
  *
  * \param Clientes* the memory direction of the Clientes
  * \return get the apellido -error NULL
  *
  */
  int Ventas_get_idVenta(Ventas* this)
 {
 	if(this!=NULL )
 	{
 	    return this->idVenta;
 	}else
             return -1;
 }

  /** \brief set the name in the Clientes
   *
   * \param Clientes* the memory direction of the Clientes
   * \param char* nombre the name of the new Clientes
   * \return int return 0 - ok -1 - error
   *
   */
 int Ventas_set_estado(Ventas* this, int estado)
 {
 	int retorno=-1;
 	if(this!=NULL )
 	{
             this->estado=estado;
 	    retorno=0;
 	}
 	return retorno;
 }

 /** \brief get the apellido in the Clientes
  *
  * \param Clientes* the memory direction of the Clientes
  * \return get the apellido -error NULL
  *
  */
 int Ventas_get_estado(Ventas* this)
 {
 	if(this!=NULL )
 	{
 		return this->estado;
 	}else
 			 return -1;
 }

 //Funciones Criterio



 /** \brief Print Ventas
   *
   * \param void* pElemnto the element of the LinkedList
   * \return 1
   *
   */

int returnMap1(void* pElemnto)
{
	Ventas* empleado = (Ventas*)pElemnto;
	printf(" %-15d | %-15d | %-15d | %-15s | %-15d | %-15d |\n", Ventas_get_idVenta(empleado),Ventas_get_idCliente(empleado),Ventas_get_CantidadAfiches(empleado),Ventas_get_nombreArchivo(empleado),Ventas_get_Zona(empleado),Ventas_get_estado(empleado));
	return 1;
}

/** \brief Print Ventas with state sin cobrar
  *
  * \param void* pElemnto the element of the LinkedList
  * \return 1
  *
  */
int stateVentas(void* pElemnto)
{
	Ventas* empleado = (Ventas*)pElemnto;
	int state = Ventas_get_estado(empleado);
	if(state==0)
		printf(" %-15d | %-15d | %-15d | %-15s | %-15d | %-15d |\n", Ventas_get_idVenta(empleado),Ventas_get_idCliente(empleado),Ventas_get_CantidadAfiches(empleado),Ventas_get_nombreArchivo(empleado),Ventas_get_Zona(empleado),Ventas_get_estado(empleado));
	return 1;
}

/** \brief find the Id of Id Ventas
  *
  * \param void* pElemnto the element of the LinkedList
  * \return 1 or 0 error
  *
  */

int FindIdVentas(void* pElemnto,int indice)
{
	Ventas* empleado = (Ventas*)pElemnto;
	if(Ventas_get_idVenta(empleado) == indice)
		return 1;
	else
		return 0;

}
/** \brief return the estados Cobrados and the id is equal
  *
  * \param void* pElemnto the element of the LinkedList
  * \return 1
  *
  */
int FindCobradas(void* pElemnto,int indice)
{
	Ventas* empleado = (Ventas*)pElemnto;
	if( Ventas_get_estado(empleado)==1 && Ventas_get_idCliente(empleado) == indice)
		return 1;
	else
		return 0;
}


/** \brief return cantidad de afiches if the estados Cobrados and the id is equal
  *
  * \param void* pElemnto the element of the LinkedList
  * \return cantidad de afiches
  *
  */
int FindAfiches(void* pElemnto,int indice)
{
	Ventas* empleado = (Ventas*)pElemnto;
	if( Ventas_get_estado(empleado)==1 && Ventas_get_idCliente(empleado) == indice)
		return Ventas_get_CantidadAfiches(empleado);
	else
		return 0;
}

/** \brief return cantidad de afiches if the estados Cobrados and the id is equal
  *
  * \param void* pElemnto the element of the LinkedList
  * \return 1-ok 0-error
  *
  */
int FindaCobrar(void* pElemnto,int indice)
{
	Ventas* empleado = (Ventas*)pElemnto;
	if( Ventas_get_estado(empleado)==0  && Ventas_get_idCliente(empleado) == indice)
		return 1;
	else
		return 0;

}


