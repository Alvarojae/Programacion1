
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListUser,LinkedList* pArrayListPost);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_FindId(LinkedList* pArrayListEmployee,int idUser);
int controller_FindNextId(LinkedList* pArrayListEmployee);
int controller_ListEnvio(LinkedList* pArrayListEnvio);
LinkedList* controller_zonas(LinkedList* pArrayListEnvio);
int controller_zonasNoRepetidas(LinkedList* pArrayListEnvio);
int controller_loadFromTextDos(char* path , LinkedList* pArray);
void zona_generarLista(LinkedList* pArrayZona, LinkedList* pArrayEnvio);
int zona_estaEnMiLista(LinkedList* pArrayZona, char* zonaNombre);
void zona_imprimir(LinkedList* pArrayEnvio);

LinkedList* generarListaZona(LinkedList* test);
void printTest(LinkedList* test);

char* agregarCsv(char* zona);
