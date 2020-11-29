#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Post.h"
#include "usuario.h"
#include "utn.h"

int main()
{
	setbuf(stdout, NULL);
	char seguir='s';
	int bandera=0;
	int banderaLoad=0;

    LinkedList* listaPost = ll_newLinkedList();
    LinkedList* listaUsuario = ll_newLinkedList();

    do{
    	if(bandera!=0)
		{
			system("pause");
			system("cls");
		}
		bandera++;
        switch(menu())
        {
            case 1:
            	if(banderaLoad == 0)
				{
					if((controller_loadFromText("mensajes.csv",listaPost)==0 &&
						controller_loadFromTextDos("usuarios.csv",listaUsuario)==0)													)
					{
						printf("se cargo correctamente los empleado\n");
						banderaLoad++;
					}
					else
						printf("no se pudo cargar los empleado\n");
				}else
					printf("Ya se cargo los usuarios\n");
                // Cargar los datos (data.csv)
                break;

            case 2:
            	if(banderaLoad != 0)
            	{
            		ll_map(listaUsuario, usuario_imprimirTodos);
					ll_map(listaPost,Post_imprimirTodos);
            	}
			   break;

            case 3:
            	if(banderaLoad != 0)
            	{
            		ll_sort(listaUsuario, sortUsuario, 0);
            		controller_saveAsText("feed.csv", listaUsuario, listaPost);
            		//ll_map(listaEnvios, calcularCostos);
            		//controller_ListEnvio(listaEnvios);
            	}
            	else
					printf("Se deben cargar los usuarios primero\n");
            	break;

            case 4:
            	if(banderaLoad != 0)
            	{

            		//controller_zonas(listaEnvios);
            	}
            	else
					printf("Se deben cargar los usuarios primero\n");
                       	break;

            case 5:
            	//Salir
            	seguir='n';
				break;
        }
    }while(seguir=='s');

    return 0;
}

