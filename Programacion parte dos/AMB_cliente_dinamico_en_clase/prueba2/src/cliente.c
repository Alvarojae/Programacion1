#include "cliente.h"

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



Cliente* cliente_newConParametros(int id, char* name,char* lastName, char* cuit)
{
	Cliente* pc=NULL;
	if(id>0 && name!=NULL && lastName!=NULL && cuit!=NULL)
	{
		pc = (Cliente*)malloc(sizeof(Cliente));
		if(pc!=NULL)
		{
			pc->id=id;
			pc->isEmpty=0;
			strncpy(pc->name,name,sizeof(pc->name));
			strncpy(pc->lastName,lastName,sizeof(pc->lastName));
			strncpy(pc->cuit,cuit,sizeof(pc->cuit));
		}
	}
	return pc;
}

void cliente_delete(Cliente* pc)
{
	if(pc!=NULL)
		free(pc);
}




/**
 * @fn int cliente_HardCodeo(Cliente*)
 * @brief Funcion que da valores iniciales a 5 clientes
 *
 * @param pArray: El puntero al array de tipo Cliente
 * @return (-1) Error (0) todo OK
 */
int cliente_HardCodeo(Cliente* pArray[])
{
    int output = -1;
    int bufferID[5] =                   {   100,                  101,            102,            103,            104           };
    char bufferName[5][SIZE_STR] =      {   "EDGARDO HORACIO",    "ANGUS",        "BRIAN",        "RICARDO",      "BRUCE"       };
    char bufferLastName[5][SIZE_STR] =  {   "LORENZO",            "DICIKINSON",   "JHONSON",      "IORIO",        "DICIKINSON"  };
    char bufferCuit[5][SIZE_STR] =      {   "20336330972",          "20456787196",   "32689210751",   "29903221487",   "41107389873" };
    Cliente* pc;

    if (pArray != NULL)
    {
        for (int x = 0; x < 5; x++)
        {
        	// 1) construyo el cliente
        	pc = cliente_newConParametros(bufferID[x],
        							 	  bufferName[x],
									      bufferLastName[x],
									      bufferCuit[x]);

        	// 2) agrego el cliente al array
        	pArray[x] = pc;

        }
        output = 0;
    }
    return output;
}

/**
 * @fn int cliente_Init(Cliente*, int)
 * @brief Funcion que setea todos los campos isEmpty de cada elemento de tipo Cliente en TRUE
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo Cliente
 * @return (-1) Error (0) todo ok
 */
// Array de elementos "Cliente"
//int cliente_Init(Cliente *pArray, int len)
//int cliente_Init(Cliente pArray[], int len)

int cliente_Init(Cliente* pArray[], int len)
//int cliente_Init(Cliente** pArray, int len)
{
    int output = -1;
    if (pArray != NULL && len > 0)
    {
        for (int x = 0; x < len; x++)
        {
            pArray[x] = NULL;
        	//*(pArray+x) = NULL;
        }
        output = 0;
    }
    return output;
}

/**
 * @fn int cliente_FindById(Cliente*, int, int, int*)
 * @brief Funcion que encuentra el indice de un elemento de tipo Cliente en base al ID
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo Cliente
 * @param id: El ID a comparar con los elementos del array
 * @param indexPosition: El puntero a int donde se guardara la posiscion del elemento, si se encuentra
 * @return (-1) Error (0) todo OK
 */
int cliente_FindById(Cliente* pArray[], int len, int id, int *indexPosition)
{
    int output = -1;
    if (pArray != NULL && indexPosition != NULL && len > 0 && id > 0)
    {
        for (int x = 0; x < len; x++)
        {
            //if (pArray[x].id == id && pArray[x].isEmpty == FALSE)
        	if(pArray[x]!=NULL)
            {
        		printf("comparo id %d con id %d\n",pArray[x]->id,id);
        		if(pArray[x]->id == id) // el id de ese cliente es igual al que reicibi como arg
        		//if( (*(pArray+x))->id == id)
        		{
        			printf("lo encontre! \n");
        			*indexPosition = x;
                	output = 0;
                	break;
        		}
            }
        }
    }
    return output;
}

/**
 * @fn int cliente_DoesIdExist(Cliente*, int, int)
 * @brief Funcion que pregunta si existe un determinado ID dentro del array de tipo Cliente
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo cliente
 * @param id: El ID a comparar
 * @return (0) No existe (1) Existe
 */
int cliente_DoesIdExist(Cliente *pArray, int len, int id) {

    int output = 0;
    if (pArray != NULL && len > 0 && id > 0) {
        for (int x = 0; x < len; x++) {
            if (pArray[x].id == id && pArray[x].isEmpty == FALSE) {
                output = 1;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int cliente_FindFree(Cliente*, int, int*)
 * @brief Funcion que encuentra el primer indice libre dentro del array de tipo Cliente
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo cliente
 * @param freeIndexPosition: EL puntero a int donde se guardara el indice libre
 * @return (-1) Error (0) todo OK
 */
int cliente_FindFree(Cliente *pArray, int len, int *freeIndexPosition) {
    int output = -1;
    if (pArray != NULL && freeIndexPosition != NULL && len > 0) {
        for (int x = 0; x < len; x++) {
            if (pArray[x].isEmpty == TRUE) {
                *freeIndexPosition = x;
                output = 0;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int cliente_GenerateId(int*)
 * @brief Funcion privada que calcula un id de forma incremental
 *
 * @param ClienteID: El puntero a int donde se guardara el ID generado
 * @return (-1) Error (0) todo OK
 */
static int cliente_GenerateId(int *ClienteID) {

    int output = -1;
    static int id = 105;
    if (ClienteID != NULL) {
        *ClienteID = id++;
        output = 0;
    }
    return output;
}

/**
 * @fn int cliente_IsCuitValid(char*)
 * @brief Funcion que solicita verifica longitud de cuit
 *
 * @param bufferCuit: El char que almacena el cuit a verificar
 * @return (0) Error (1) todo OK
 */
int cliente_IsCuitValid(char *bufferCuit)
{
	int output = 0;
	int contador = 0;
	if(bufferCuit != NULL)
	{
		for(int x = 0; bufferCuit[x] != '\0'; x++)
		{
			contador++;
		}
		if(contador == 11)
		{
			output = 1;
		}
	}
	return output;
}

/**
 * @fn int cliente_Create(Cliente*, int)
 * @brief Funcion que solicita los campos de un elemento de tipo Cliente
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo cliente
 * @return (-1) Error (0) todo OK
 */
int cliente_Create(Cliente *pArray, int len) {

    int output = -1;
    Cliente bufferAux;
    int bufferIndex;
    int bufferResultado;

    if (pArray != NULL && len > 0 && !(cliente_FindFree(pArray, len, &bufferIndex))) {
        if (!(utn_getString("(a). Ingrese nombre: ", "Error, reintentos", bufferAux.name, SIZE_STR, 3))
                && !(utn_getString("(b). Ingrese apellido: ", "Error, reintentos", bufferAux.lastName, SIZE_STR, 3))
                && !(cliente_GenerateId(&bufferAux.id)))
        {
            do
            {
                if(!(utn_getStringWithOnlyNumbers("(c). Ingrese CUIT de 11 digitos: ", "Error - solo numeros,  reintentos", bufferAux.cuit, SIZE_STR, 3)))
                {
                    bufferResultado = cliente_IsCuitValid(bufferAux.cuit);
                }
            }while(bufferResultado == 0);

            pArray[bufferIndex] = bufferAux;
            pArray[bufferIndex].isEmpty = FALSE;

            output = 0;
        }
    }
    return output;
}

/**
 * @fn int cliente_Remove(Cliente*, int, int)
 * @brief Funcion que busca cliente por ID y si existe lo da de baja
 *
 * @param pArray: El puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo Cliente
 * @param id: El id a comparar
 * @return (-1) Error (0) todo OK
 */
int cliente_Remove(Cliente* pArray[], int len, int id)
{
    int output = -1;
    int indiceABorrar;
    if(pArray != NULL && len > 0 && id >0)
    {
        if(cliente_FindById(pArray,len,id,&indiceABorrar)==0)
        {
        	// borro cliente posicion "indiceABorrar"
        	//1) free en direccion de mem de cliente
        	//2) poner null en array
        	cliente_delete(pArray[indiceABorrar]);
        	pArray[indiceABorrar]=NULL;
        	output=0;
        }
    }
    return output;
}

/**
 * @fn int cliente_Modify(Cliente*, int)
 * @brief Funcion que permite modificar campos de un elemento de tipo Cliente
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo cliente
 * @return (-1) Error (0) todo OK
 */
int cliente_Modify(Cliente *pArray, int len) {
    int output = -1;
    int opcionMenuModificaciones;
    int flag;
    int bufferID;
    int bufferIndex;
    int bufferResultado;
    Cliente bufferAux;

    if (pArray != NULL && len > 0) {
        do
        {
            if (!(menu_Modificar(&opcionMenuModificaciones)))
            {
                switch (opcionMenuModificaciones)
                {
                case 1:
                    if (!cliente_printAll(pArray, len))
                    {
                        output = 1;
                    }
                    break;
                case 2:
                    if (!(utn_getInt("\nINGRESE ID DEL CLIENTE: ","Error, reintentos", &bufferID, 3)))
                    {
                        if (cliente_FindById(pArray, len, bufferID, &bufferIndex))
                        {
                            printf("ID INVALIDO, VUELVA A LISTAR COMPLETAR O SALGA\n");
                        }
                        else
                        {
                            flag = 1;
                        }
                        output = 1;
                    }
                    break;
                case 3:
                    if (flag == 1)
                    {
                        if (!(utn_getString("\n(a). Ingrese nuevo nombre: ", "Error, reintentos", bufferAux.name,
                                SIZE_STR, 3)))
                        {
                            strncpy(pArray[bufferIndex].name, bufferAux.name, SIZE_STR);
                            output = 0;
                        }
                    }
                    else
                    {
                        printf("DEBE INGRESAR ID PRIMERO\n");
                        output = 1;
                    }
                    break;
                case 4:
                    if (flag == 1)
                    {
                        if (!(utn_getString("(b). Ingrese nuevo apellido: ","Error, reintentos", bufferAux.lastName,SIZE_STR, 3)))
                        {
                            strncpy(pArray[bufferIndex].lastName,bufferAux.lastName, SIZE_STR);
                            output = 0;
                        }
                    }
                    else
                    {
                        printf("DEBE INGRESAR ID PRIMERO\n");
                        output = 1;
                    }
                    break;
                case 5:
                    if (flag == 1)
                    {
                        do
                        {
                            if(!(utn_getStringWithOnlyNumbers("(c). Ingrese nuevo CUIT de 11 digitos: ", "Error - solo numeros,  reintentos", bufferAux.cuit, SIZE_STR, 3)))
                            {
                                bufferResultado = cliente_IsCuitValid(bufferAux.cuit);
                            }
                        }while(bufferResultado == 0);
                            strncpy(pArray[bufferIndex].cuit,bufferAux.cuit, SIZE_STR);
                            output = 0;
                    }
                    else
                    {
                        printf("DEBE INGRESAR ID PRIMERO\n");
                        output = 1;
                    }
                    break;
                case 6:
                   printf("SALIENDO AL MENU PRINCIPAL\n");
                    break;
                default:
                    printf("ERROR, OPCION INVALIDA\n");
                }
            }
            printf("\nPresione una tecla para continuar");
            __fpurge(stdin);
            getchar();
            system("clear");
        } while (opcionMenuModificaciones != 6);
    }
    return output;
}

/**
 * @fn int cliente_PrintOne(Cliente)
 * @brief Funcion que muestra por pantalla un elemento de tipo Cliente
 *
 * @param Cliente: El elemento de tipo Cliente
 * @return (-1) Error (0) todo OK
 */
int cliente_PrintOne(Cliente* pCliente)
{
    int output = -1;
    if(pCliente!=NULL)
    {
        printf("# %d %15s %15s %12s\n", pCliente->id, pCliente->name,
        		pCliente->lastName, pCliente->cuit);
        output = 0;
    }
    return output;
}

/**
 * @fn int cliente_printAll(Cliente*, int)
 * @brief Funcion que imprime todos los elementos de un array de tipo Cliente
 *
 * @param pArray: El puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo cliente
 * @return (-1) Error (0) todo OK
 */
int cliente_printAll(Cliente* pArray[], int len)
{
    int output = -1;
    if (pArray != NULL && len > 0)
    {
        printColumn();
        for (int x = 0; x < len; x++)
        {
            cliente_PrintOne(pArray[x]);
        }
        output = 0;
    }
    return output;
}




