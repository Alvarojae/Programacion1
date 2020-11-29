
#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999

typedef struct
{ 
	char name[51];
	int id;
	int isEmpty;
}Fantasma;

int initList(Fantasma* list, int len);
int buscarLibre(Fantasma* arrayAlumnos, int len);
int add(Fantasma* list, int len);
int print(Fantasma* list, int len);
int mostrar(Fantasma* list,int len);
int removeNac(Fantasma* list, int len);
int findId(Fantasma* list,int len,int id);
int modificar(Fantasma* list,int len);
int sortNac(Fantasma* list, int len);


int menu();

