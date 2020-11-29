#ifndef contatracion_H_
#define contatracion_H_

#include "pantalla.h"

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999
#define MAX_CONTRATACIONES 1000


typedef struct
{ 
	char name[51];
	char cuitCliente[51];
	int cantidadDeDias;
	int idPantalla;
	int id;
	int isEmpty;

}Contratacion;

int contra_initList(Contratacion* list, int len);
int contra_buscarLibre(Contratacion* arrayAlumnos, int len);
int contra_add(Contratacion* list, int lenContra, Pantalla* listPant, int lenPant);
int contra_print(Contratacion* list, int len);
int contra_mostrar(Contratacion* list,int len);
int contra_remove(Contratacion* list, int lenCon, Pantalla* listPant,int lenPant);
int contra_findId(Contratacion* list,int len,int id);
int contra_modificar(Contratacion* list,int len, int indice);
int contra_sortNac(Contratacion* list, int len);
int contra_mostrarPanYCon(Contratacion* list,int lenCon,char* cuit,Pantalla* listPant,int lenPant);

#endif
