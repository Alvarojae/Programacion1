#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuario.h"

#include "LinkedList.h"
#include "Post.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"


Usuario* Usuario_new()
{   Usuario* new =(Usuario*)malloc(sizeof(Usuario));
    return new;
}
Usuario* Usuario_newParametros(char* id_usuario,char* nick,char* popularidad)
{
    Usuario* this = Usuario_new();
    if(this != NULL)
    {
	   if( Usuario_set_nick(this,nick) != -1 &&
	       Usuario_set_id_usuario(this,atoi(id_usuario)) != -1 &&
	       Usuario_set_popularidad(this,atoi(popularidad)) != -1 )
	   {
               return this;
	   }
    }
    return NULL;
}
void Usuario_delete(Usuario* this)
{
	free(this);
}
int Usuario_set_nick(Usuario* this, char* nick)
{
	int retorno=-1;
	if(this!=NULL)
	{
            strncpy(this->nick,nick,(int)sizeof(this->nick));
	    retorno=0;
	}
	return retorno;
}
 char* Usuario_get_nick(Usuario* this)
{
	if(this!=NULL )
	{
	    return this->nick;
	}else
            return NULL;
}
int Usuario_set_id_usuario(Usuario* this, int id_usuario)
{
	int retorno=-1;
	if(this!=NULL )
	{
            this->id_usuario=id_usuario;
	    retorno=0;
	}
	return retorno;
}
 int Usuario_get_id_usuario(Usuario* this)
{
	if(this!=NULL )
	{
	    return this->id_usuario;
	}else
            return -1;
}
int Usuario_set_popularidad(Usuario* this, int popularidad)
{
	int retorno=-1;
	if(this!=NULL )
	{
            this->popularidad=popularidad;
	    retorno=0;
	}
	return retorno;
}
 int Usuario_get_popularidad(Usuario* this)
{
	if(this!=NULL )
	{
	    return this->popularidad;
	}else
		return -1;
}


 int usuario_imprimirTodos(void*thisA)
 {
     Usuario *UsuarioA = thisA;
     printf(" %04d | %-25s | %-6d |\n", Usuario_get_id_usuario(UsuarioA),Usuario_get_nick(UsuarioA),Usuario_get_popularidad(UsuarioA));
     return 1;
 }

 int sortUsuario(void* this1, void* this2)
 {
     int retorno = 0;
     Usuario* auxEmp1 = (Usuario*)this1;
     Usuario* auxEmp2 = (Usuario*)this2;

     if(this1 != NULL && this2 != NULL)

     {
         if(Usuario_get_popularidad(auxEmp1) > Usuario_get_popularidad(auxEmp2))
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
