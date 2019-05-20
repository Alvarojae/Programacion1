#include <stdio.h>
#include <stdlib.h> //(para memoria dinamica)

int main()
{
    int* pnum;
    int* pnumAuxiliar;


    pnum = (int*) malloc(sizeof(int)* 5);
    if(pnum==NULL) /**< validamos si nos devuelve los bitts, si no lo consigue cierra el programa  */
    {
        printf("no se consiguio memoria\n");
        system("pause");
        exit(1);
    }





    for(int i =0 ; i<5;i++)
    {
        printf("ingrese  numero = ");
        scanf("%d",pnum+i) ;
    }



    for(int i =0 ; i<5;i++)
    {
        printf("\n indice = %d\n valor = %d\n",i,*(pnum+i));
    }

    pnumAuxiliar  = (int*) realloc(pnum, sizeof(int)*10);

    if(pnumAuxiliar!=NULL)
    {
        pnum = pnumAuxiliar ;

     for(int i =5 ; i<10;i++)
    {
        printf("ingrese  numero = ");
        scanf("%d",(pnum+i)) ;
    }



    for(int i =0 ; i<10;i++)
    {
        printf("\n indice = %d\n valor = %d\n",i,*(pnum+i));
    }

    }
    /*
    printf("ingrese un numero = ");
    scanf("%d", pnum);
    printf("\n\nLa direccion de memoria = ");
    printf("%p\n",  pnum);
    printf("El numero ingresado es = ");
    printf("%d\n", *pnum);
    */


    free(pnum); // -> libera espacio de memoria

    return 0;
}

/** \brief
 * malloc -> memory allocate
 * void* malloc(unsigned int bytes);
 *  void* malloc(sizeof(int) o 4); -> mejor poner sizeof(int)
 *  pnumAuxiliar = (int*) realloc(puntero, tamaño) -> sirve para agrandar
 *  vec = (int*) calloc(10 , sizeof (int)*10);
 */

