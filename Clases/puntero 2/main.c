/*
#include <stdio.h>
#include <stdlib.h>
void mostrarCadena(char* punteroCadena);
void mostrarCadena2(char* punteroCadena);
int main()
{
    char palabra[] = "hola";
    char* p;
    p=palabra;
    printf("\n\n mostrar cadena 1 = \n");
    mostrarCadena(p);
    printf("\n\n mostrar cadena 2 = \n");
     mostrarCadena2(p);
    return 0;
}

void mostrarCadena(char* punteroCadena)
{

    while(*punteroCadena != '\0')
    {
        printf("\n%p = ",punteroCadena);
        printf("%c",*punteroCadena);
        punteroCadena++;
    }
}
void mostrarCadena2(char* punteroCadena)
{
    int i=0;

    while(*(punteroCadena+i) != '\0')
    {
        printf("\n%p = ",punteroCadena);
        printf("%c",*(punteroCadena+i));
        i++;

    }
}

--------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10;
    int *puntero;
    int **punteroPuntero;
    puntero = &a; // Obtenemos la posición de memoria
    punteroPuntero = &puntero; // Obtenemos la posición de memoria
    printf("valor de a = 10\n");
    printf("ingrese valor de a = ");
    scanf("%d", *punteroPuntero);
    printf("primera ves %d\n",**punteroPuntero);
    printf("segunda ves %d\n", *puntero);
    printf("tercera ves %d\n",  a);

    return 0;
}


