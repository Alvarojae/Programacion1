int controller_loadFromText(char* path , LinkedList* pArray);
int controller_loadFromTextDos(char* path , LinkedList* pArray);
int controller_addCliente(LinkedList* pArrayListEmployee);
int controller_addVentas(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes);
int controller_ModifyVentas(LinkedList* pArrayListVentas, LinkedList* pArrayListClientes);
int controller_cobrarVentas(LinkedList* pArrayListVentas, LinkedList* pArrayListClientes);
char* agregarCsv(char* zona);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsTextVentas(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsTextCobradas(char* path , LinkedList* pArrayListClientes,LinkedList* pArrayListVentas,int estado);
int controller_FindMaxAndMin(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes,int estado);
int controller_FindMaxAfichesVendidos(LinkedList* pArrayListVentas,LinkedList* pArrayListClientes);
int controller_FindId(LinkedList* pArrayListEmployee,int idUser);
int controller_FindNextIdClientes(LinkedList* pArrayListEmployee);
int controller_FindNextIdVentas(LinkedList* pArrayListEmployee);
int cuitRepetido(LinkedList* pArrayListEmployee, char* cuit);
int idExist(LinkedList* pArrayListEmployee, int id);
int idExistVentas(LinkedList* pArrayListEmployee, int id);


