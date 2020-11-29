#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "Post.h"


Post* Post_new()
{   Post* new =(Post*)malloc(sizeof(Post));
    return new;
}
Post* Post_newParametros(char* id_mensaje,char* id_usuario,char* popularidad,char* mensaje)
{
    Post* this = Post_new();
    if(this != NULL)
    {
	   if( Post_set_id_mensaje(this,atoi(id_mensaje)) != -1 &&
	       Post_set_mensaje(this,mensaje) != -1 &&
	       Post_set_popularidad(this,atoi(popularidad)) != -1 &&
		   Post_set_id_usuario(this,atoi(id_usuario)) != -1 )
	   {
               return this;
	   }
    }
    return NULL;
}
void Post_delete(Post* this)
{
	free(this);
}
int Post_set_id_mensaje(Post* this, int id_mensaje)
{
	int retorno=-1;
	if(this!=NULL)
	{
            this->id_mensaje=id_mensaje;
	    retorno=0;
	}
	return retorno;
}
 int Post_get_id_mensaje(Post* this)
{
	if(this!=NULL )
	{
	    return this->id_mensaje;
	}else
            return -1;
}
int Post_set_mensaje(Post* this, char* mensaje)
{
	int retorno=-1;
	if(this!=NULL )
	{
		strncpy(this->mensaje,mensaje,(int)sizeof(this->mensaje));
	    retorno=0;
	}
	return retorno;
}
 char* Post_get_mensaje(Post* this)
{
	if(this!=NULL )
	{
	    return this->mensaje;
	}else
            return NULL;
}
int Post_set_popularidad(Post* this, int popularidad)
{
	int retorno=-1;
	if(this!=NULL )
	{
            this->popularidad=popularidad;
	    retorno=0;
	}
	return retorno;
}
 int Post_get_popularidad(Post* this)
{
	if(this!=NULL )
	{
	    return this->popularidad;
	}else
            return -1;
}
int Post_set_id_usuario(Post* this, int id_usuario)
{
	int retorno=-1;
	if(this!=NULL )
	{
            this->id_usuario=id_usuario;
	    retorno=0;
	}
	return retorno;
}
 int Post_get_id_usuario(Post* this)
{
	if(this!=NULL )
	{
	    return this->id_usuario;
	}else
            return -1;
}




 int envio_allSet(Post* this,char* mensaje,int id_mensaje,int popularidad, int id_usuario)
 {
 	if (this!=NULL)
 	{
 		Post_set_id_mensaje(this, id_mensaje);
		Post_set_id_usuario(this, id_usuario);
		Post_set_mensaje(this, mensaje);
		Post_set_popularidad(this, popularidad);
 		return 0;
 	}
 	return -1;
 }



 int Post_imprimirTodos(void*thisA)
 {
     Post *UsuarioA = thisA;

     printf(" %04d | %-3d | %-6d | %s |\n", Post_get_id_mensaje(UsuarioA),Post_get_id_usuario(UsuarioA),Post_get_popularidad(UsuarioA),Post_get_mensaje(UsuarioA));
     return 1;
 }






//funciones de Criterio
/*
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
*/
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
/*

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



*/









