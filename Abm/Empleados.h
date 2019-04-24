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
void borrarBaseDeDatos(sEmpleado vec[], int tam);
void mostrarGrupo ( sEmpleado emp[], int tam, sSector sectorcito[]);
int buscarEspacioLibre (sEmpleado emp[], int tam);
int buscarEmpleado(sEmpleado emp[], int tam, int legajo);
void altaEmpleado (sEmpleado emp[], int tam);
void bajaEmpleado (sEmpleado emp[], int tam);
void modificacionEmpleado (sEmpleado emp[], int tam);
void ordenarPor(sEmpleado emp[], int tam);
void obtenerSector (sSector sectores[], int tam, int id, char desc[]);
void mostrarPorSector ( sEmpleado emp[], sSector succ[], int tam, int tam2);

#endif
