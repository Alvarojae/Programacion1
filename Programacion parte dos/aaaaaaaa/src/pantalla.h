#ifndef PANTALLA_H_
#define PANTALLA_H_




#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999
#define MAX_SRUCT_PANTALLAS 100

typedef struct
{ 
	char name[51];
	char direccion[51];
	float precioPublicidad;
	int tipoDePantalla;
	int id;
	int isEmpty;
}Pantalla;

int initList(Pantalla* list, int len);
int buscarLibre(Pantalla* list, int len);
int add(Pantalla* list, int len);
int pantalla_print(Pantalla* list, int len);
int pantalla_mostrar(Pantalla* list,int len);
int removeNac(Pantalla* list, int len);
int pantalla_findId(Pantalla* list,int len,int id);
int modificar(Pantalla* list,int len);
int sortNac(Pantalla* list, int len);


int menu();

#endif /* ASDASDAS_H_ */
