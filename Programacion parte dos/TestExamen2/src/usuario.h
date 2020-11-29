
typedef struct
{
   char nick[51];
   int id_usuario;
   int popularidad;
   int idCamion;
}Usuario;


int usuario_imprimirTodos(void*thisA);
Usuario* Usuario_newParametros(char* nick,char* id_usuario,char* popularidad);
void Usuario_delete(Usuario* this);
Usuario* Usuario_new();
int Usuario_set_nick(Usuario* this, char* nick);
char* Usuario_get_nick(Usuario* this);
int Usuario_set_id_usuario(Usuario* this, int id_usuario);
int Usuario_get_id_usuario(Usuario* this);
int Usuario_set_popularidad(Usuario* this, int popularidad);
int Usuario_get_popularidad(Usuario* this);
int sortUsuario(void* this1, void* this2);

