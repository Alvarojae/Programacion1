typedef struct
{
   int id_mensaje;
   char mensaje[2000];
   int popularidad;
   int id_usuario;
}Post;


int Post_imprimirTodos(void*thisA);
Post* Post_newParametros(char* id_mensaje,char* id_usuario,char* popularidad,char* mensaje);
void Post_delete(Post* this);
Post* Post_new();
int Post_set_id_mensaje(Post* this, int id_mensaje);
int Post_get_id_mensaje(Post* this);
int Post_set_mensaje(Post* this, char* mensaje);
char* Post_get_mensaje(Post* this);
int Post_set_popularidad(Post* this, int popularidad);
int Post_get_popularidad(Post* this);
int Post_set_id_usuario(Post* this, int id_usuario);
int Post_get_id_usuario(Post* this);
int envio_allSet(Post* this,char* mensaje,int id_mensaje,int popularidad, int id_usuario);

int calcularCostos(void* pElemnto);
int sortNameMap(void* this1, void* this2);
int printMap(void* pElemnto);
int returnMap(void* pElemnto);
int returnNameMap(void* pElemnto);
float returnSueldoMap(void* pElemnto);
int returnZonaMap(void* pElemnto,char* zona);

/*
Zona* zona_new();
int zona_getZona(Zona* this,char* zona);
int zona_setZona(Zona* this,char* zona);
Zona* zona_newParam(char* nombre);

int sortZona(void* this1, void* this2);

*/
