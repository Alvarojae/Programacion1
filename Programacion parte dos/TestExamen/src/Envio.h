#ifndef envio_H_INCLUDED
#define envio_H_INCLUDED
typedef struct
{
    int idProducto;
    int idCamion;
    int km;
    int tipoDeEntrega;
    char zona[128];
    char nombre[128];
    int costo;

}Envio;

typedef struct
{
	char zona[148];
}Zona;

Envio* envio_new();
Envio* envio_newParametros(char* idEnvio,char* nombre,char* idCamion,char* zona,char* km, char* entrega);
void envio_delete();


int envio_setIdProducto(Envio* this,int id);
int envio_getIdProducto(Envio* this,int* id);

int envio_setIdCamion(Envio* this,int id);
int envio_getIdCamion(Envio* this,int* id);

int envio_setKm(Envio* this,int km);
int envio_getKm(Envio* this,int* km);

int envio_setTipoDeEntrega(Envio* this,int tipoDeEntrega);
int envio_getTipoDeEntrega(Envio* this,int* tipoDeEntrega);

int envio_setCosto(Envio* this,int costo);
int envio_getCosto(Envio* this,int* costo);

int envio_setNombre(Envio* this,char* nombre);
int envio_getNombre(Envio* this,char* nombre);

int envio_setZona(Envio* this,char* zona);
int envio_getZona(Envio* this,char* zona);

int envio_generarNuevoId(void);
int envio_validName(char* cadena,int limite);
int envio_allSet(Envio* this,char* nombre,char* zona ,int km,int IdCamion, int IdProducto,int TipoDeEntrega,int costo);
int envio_allGet(Envio* this,char* nombre,char* zona ,int* km,int* IdCamion, int* IdProducto,int* TipoDeEntrega,int* costo);

int calcularCostos(void* pElemnto);
int sortNameMap(void* this1, void* this2);
int printMap(void* pElemnto);
int returnMap(void* pElemnto);
int returnNameMap(void* pElemnto);
float returnSueldoMap(void* pElemnto);
int returnZonaMap(void* pElemnto,char* zona);


Zona* zona_new();
int zona_getZona(Zona* this,char* zona);
int zona_setZona(Zona* this,char* zona);
Zona* zona_newParam(char* nombre);

int sortZona(void* this1, void* this2);
#endif // envio_H_INCLUDED

