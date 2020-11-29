#ifndef cliente_H_
#define cliente_H_

#include "publicacion.h"



#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999
#define MAX_SRUCT_CLIENTES 100



typedef struct
{ 
	int idCliente;
	char name[51];
	char lastName[51];
	char cuit[51];
	int isEmpty;
}Cliente;

int cliente_initList(Cliente* list, int len);
int cliente_buscarLibre(Cliente* list, int len);
int cliente_add(Cliente* list, int len);
int cliente_print(Cliente* list, int len);
int cliente_mostrar(Cliente* list,int len);
int cliente_buscarUsuarioDeAlta(Cliente * list, int len);
int cliente_findId(Cliente* list,int len,int id);
int cliente_modificar(Cliente* list,int len);
int cliente_altaForzada(Cliente * pArray, int limite , char * nombre, char * apellido, char * cuit);

//int cliente_sortByName(Cliente* list, int len, int order);


#endif
