#ifndef Stools_Empleado_H_INCLUDED
#define Stools_Empleado_H_INCLUDED

typedef struct {

int dia,mes,year;

} fechaNacimiento;

typedef struct {

    int id;
    char descripcion[20];

} sSector;

typedef struct {

    int estado;
    int legajo;
    float sueldo;
    char genero;
    char nombre[100];
    fechaNacimiento fechNac;
    int idSectores;

} sEmpleado;

int menuDeOpciones();
void inicializarEmpleados(sEmpleado vec[], int tam);
void mostrarEmpleado(sSector sectores[], int tam, sEmpleado emp);
void mostrarEmpleados(sEmpleado vec[], int tam, sSector sectores[], int tamSector);
int buscarLibre(sEmpleado vec[], int tam);
int buscarEmpleado(sEmpleado vec[], int tam, int legajo);
void altaEmpleado(sEmpleado vec[], int tam, sSector sectores[], int tamSector);
int obtenerSector(sSector sectores[], int tam, int id, char desc[]);
void mostrarSectoresConEmpleados(sEmpleado empleados[], int tam, sSector sectores[], int tamSec);
void mostrarCantEmpleadosXSector(sEmpleado empleados[], int tam, sSector sectores[], int tamSec);

#endif
