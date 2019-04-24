#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
typedef struct {

int dia,mes,year;

} eFecha;

typedef struct {

//empleadoLegajo
//menuCodigo
//eFecha

}eAlmuerzo;

typedef struct {

    int id;
    char descripcion[20];

}eMenu;

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int ocupado;

} eEmpleado;

typedef struct
{

    int id;
    char descripcion[20];

} eSector;
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int obtenerSector(eSector sectores[], int tam, int id, char desc[]);
void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
int menu();
