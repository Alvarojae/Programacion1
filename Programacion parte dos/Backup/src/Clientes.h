#ifndef CLIENTES_H_
#define CLIENTES_H_


 typedef struct
{
   char nombre[148];
   char apellido[148];
   int idCliente;
   char cuit[148];

}Clientes;



Clientes* Clientes_newParametros(char* nombre,char* apellido,char* idCliente,char* cuit);
void Clientes_delete(Clientes* this);
Clientes* Clientes_new();
int Clientes_set_nombre(Clientes* this, char* nombre);
char* Clientes_get_nombre(Clientes* this);
int Clientes_set_apellido(Clientes* this, char* apellido);
char* Clientes_get_apellido(Clientes* this);
int Clientes_set_idCliente(Clientes* this, int idCliente);
int Clientes_get_idCliente(Clientes* this);
int Clientes_set_cuit(Clientes* this, char* cuit);
char* Clientes_get_cuit(Clientes* this);
int returnMap(void* pElemnto);
int PrintById(void* pElemnto, int indice);
void PrintClientes(Clientes* clientes);


#endif /* CLIENTES_H_ */
