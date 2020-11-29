#ifndef CLIENTE_H_
#define CLIENTE_H_

//#include<stdio.h>
#include"menu.h"
#include"utn.h"
#define SIZE_ARRAY_CLIENTES 100
#define SIZE_STR 51
#define FALSE 0
#define TRUE 1

typedef struct{

	int id;
	char name[SIZE_STR];
	char lastName[SIZE_STR];
	char cuit[SIZE_STR];
	int isEmpty;

}Cliente;

int cliente_Init(Cliente* pArray[], int len);
int cliente_HardCodeo(Cliente* pArray[]);
int cliente_FindFree(Cliente*, int, int*);
int cliente_FindById(Cliente* pArray[], int len, int id, int *indexPosition);
int cliente_DoesIdExist(Cliente*, int, int);
int cliente_IsCuitValid(char*);
int cliente_Create(Cliente*, int);
int cliente_Remove(Cliente* pArray[], int len, int id);
int cliente_PrintOne(Cliente* pCliente);
int cliente_printAll(Cliente* pArray[], int len);
int cliente_Modify(Cliente*, int);

#endif /* CLIENTE_H_ */
