#ifndef VENTAS_H_
#define VENTAS_H_

 typedef struct
{
   int idVenta;
   char nombreArchivo[148];
   int idCliente;
   int CantidadAfiches;
   int Zona;
   int estado;

}Ventas;



Ventas* Ventas_newParametros(char* nombreArchivo,char* idCliente,char* CantidadAfiches,char* Zona, char* idVenta, char* estado);
void Ventas_delete(Ventas* this);
Ventas* Ventas_new();
int Ventas_set_nombreArchivo(Ventas* this, char* nombreArchivo);
char* Ventas_get_nombreArchivo(Ventas* this);
int Ventas_set_idCliente(Ventas* this, int idCliente);
int Ventas_get_idCliente(Ventas* this);
int Ventas_set_CantidadAfiches(Ventas* this, int CantidadAfiches);
int Ventas_get_CantidadAfiches(Ventas* this);
int Ventas_set_Zona(Ventas* this, int Zona);
int Ventas_get_Zona(Ventas* this);
int Ventas_set_idVenta(Ventas* this, int idVenta);
int Ventas_get_idVenta(Ventas* this);
int Ventas_set_estado(Ventas* this, int estado);
int Ventas_get_estado(Ventas* this);
int returnMap1(void* pElemnto);
int stateVentas(void* pElemnto);
int FindIdVentas(void* pElemnto,int indice);
int FindCobradas(void* pElemnto,int indice);
int FindaCobrar(void* pElemnto,int indice);
int FindAfiches(void* pElemnto,int indice);
#endif /* VENTAS_H_ */
