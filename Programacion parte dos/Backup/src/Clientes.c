#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Ventas.h"
#include "Clientes.h"

/** \brief create the new Clientes
 *
 * \return Employee*  memory direction of new Clientes
 *
 */
Clientes* Clientes_new()
{   Clientes* new =(Clientes*)malloc(sizeof(Clientes));
    return new;
}

/** \brief add all the params to the employee
 *
 * \param char* idCliente  the idCliente of the new Clientes
 * \param char* cuit the cuit of the new Clientes
 * \param char* nombre the nombre of the new Clientes
 * \param char* apellido the apellido of the new Clientes
 * \return Employee*
 *
 */
Clientes* Clientes_newParametros(char* idCliente,char* cuit,char* nombre,char* apellido)
{
    Clientes* this = Clientes_new();

    if(this != NULL)
    {
	   if( Clientes_set_nombre(this,nombre) != -1 &&
	       Clientes_set_apellido(this,apellido) != -1 &&
	       Clientes_set_idCliente(this,atoi(idCliente)) != -1 &&
		   Clientes_set_cuit(this,cuit) != -1 )
	   {
               return this;
	   }
    }
    return NULL;
}
/** \brief free the memory direction
 *
 * \param Employee* this memory direction of the linkedList
 *
 */
void Clientes_delete(Clientes* this)
{
	free(this);
}
//------------------------------------------------

/** \brief set the name in the Clientes
 *
 * \param Clientes* the memory direction of the Clientes
 * \param char* nombre the name of the new Clientes
 * \return int return 0 - ok -1 - error
 *
 */
int Clientes_set_nombre(Clientes* this, char* nombre)
{
	int retorno=-1;
	if(this!=NULL )
	{
		strncpy(this->nombre,nombre,(int)sizeof(this->nombre));
	    retorno=0;
	}
	return retorno;
}
/** \brief set the name in the Clientes
 *
 * \param Clientes* the memory direction of the Clientes
 * \return int return 0 - ok -1 - error
 *
 */
 char* Clientes_get_nombre(Clientes* this)
{
	if(this!=NULL )
	{
	    return this->nombre;
	}else
            return NULL;
}

 //------------------------------------------------

 /** \brief set the name in the Clientes
  *
  * \param Clientes* the memory direction of the Clientes
  * \param char* nombre the name of the new Clientes
  * \return int return 0 - ok -1 - error
  *
  */
int Clientes_set_apellido(Clientes* this, char* apellido)
{
	int retorno=-1;
	if(this!=NULL )
	{
		strncpy(this->apellido,apellido,(int)sizeof(this->apellido));
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
 char* Clientes_get_apellido(Clientes* this)
{
	if(this!=NULL )
	{
	    return this->apellido;
	}else
            return NULL;
}

 /** \brief set the idCliente in the Clientes
  *
  * \param Clientes* the memory direction of the Clientes
  * \param int idCliente the name of the new Clientes
  * \return int return 0 - ok -1 - error
  *
  */
int Clientes_set_idCliente(Clientes* this, int idCliente)
{
	int retorno=-1;
	if(this!=NULL )
	{
		this->idCliente=idCliente;
	    retorno=0;
	}
	return retorno;
}

/** \brief get the idCliente in the Clientes
 *
 * \param Clientes* the memory direction of the Clientes
 * \return get the idCliente -error NULL
 *
 */
 int Clientes_get_idCliente(Clientes* this)
{
	if(this!=NULL )
	{
	    return this->idCliente;
	}else
            return -1;
}

 /** \brief set the cuit in the Clientes
  *
  * \param Clientes* the memory direction of the Clientes
  * \param char* cuit the name of the new Clientes
  * \return int return 0 - ok -1 - error
  *
  */
int Clientes_set_cuit(Clientes* this, char* cuit)
{
	int retorno=-1;
	if(this!=NULL )
	{
		strncpy(this->cuit,cuit,(int)sizeof(this->cuit));
	    retorno=0;
	}
	return retorno;
}

/** \brief get the cuit in the Clientes
 *
 * \param Clientes* the memory direction of the employee
 * \return get the cuit -error NULL
 *
 */
 char* Clientes_get_cuit(Clientes* this)
{
	if(this!=NULL )
	{
	    return this->cuit;
	}else
            return NULL;
}


 //**********************************************************************

 /** \brief Print the Clientes
  *
  * \param void* pElemnto from the LinkedList
  * \return 1
  *
  */
 int returnMap(void* pElemnto)
 {
 	Clientes* empleado = (Clientes*)pElemnto;
 	printf(" %-8d | %-15s | %-15s | %-15s |\n", Clientes_get_idCliente(empleado),Clientes_get_cuit(empleado),Clientes_get_nombre(empleado),Clientes_get_apellido(empleado));
 	return 1;
 }

 /** \brief Print the Clientes if the id is correct
  *
  * \param void* pElemnto from the LinkedList
  * \param int indice, id to compare
  * \return 1 ok - return 0 if NULL
  *
  */
int PrintById(void* pElemnto, int indice)
{
	Clientes* empleado = (Clientes*)pElemnto;
	int aux=Clientes_get_idCliente(empleado);
	if(indice == aux)
	{
		printf(" %-8d | %-15s | %-15s | %-15s", Clientes_get_idCliente(empleado),Clientes_get_cuit(empleado),Clientes_get_nombre(empleado),Clientes_get_apellido(empleado));
		return 1;
	}else
		return 0;
}

/** \brief Print the Clientes
  *
  * \param Clientes* clientes from the LinkedList
  * \return 1
  *
  */
void PrintClientes(Clientes* clientes)
{
	printf(" %-8d | %-15s | %-15s | %-15s ", Clientes_get_idCliente(clientes),Clientes_get_cuit(clientes),Clientes_get_nombre(clientes),Clientes_get_apellido(clientes));
}



