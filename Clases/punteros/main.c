/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10; //(int=tipo de dato, x=nombre, 10=valor,)


}

 &x (direccion de memoria)


 |__||__||__|
 |__||10|= x y &x
 |__||__||__|
 |__||__||__|
 |__||__||__|
 |__||__||__|
 |__||__||__|

 string tiene para mostrar la finalizacion con \0
 en puntero tiene un eof(end of file)
 printf("%x",p); (muestra la direccion de memoria en hexa)
 %x hexa
 %o octal
 -------------------------

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    int* p;

    p = &x;
    printf("%d",*p);

    return 0;
}
-------------------------------------


#include <stdio.h>
#include <stdlib.h>

void leerPuntero(int* p);
int main()
{
    int x = 10;
    printf("direccion de x = %x\n",&x);
    printf("antes de llamar a leer puntero x vale = %d\n",x);
    leerPuntero(&x);
    printf("despues de llamar a leer puntero x vale = %d\n",x);
    return 0;
}

void leerPuntero(int* p)
{
   // printf("%d",*p);
   *p = 38;
}
------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x = 10;
    int* p = &x;
    int** r = &p;
    printf("%d\n", **r);
    return 0;
}

---------------------------------------------------

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int vec[]={3, 5, 2, 4 , 3};


    printf("Esto toma el primer valor del vec(indice 0) = %d\n",*vec  );
    printf("Esto toma el primer valor del vec(indice 0) = %d\n",*(vec+1));

for(int i=0; i <5 ; i++)
{
    printf("indice = %d\n valor= %d\n",i,*(vec+i));
}




    return 0;
}
-------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void mostrarVector1(int vec[], int tam); //(vectorial)
void mostrarVector2(int vec[], int tam);//(puntero)
void mostrarVector3(int* vec, int tam); //(puntero pero muestra vectorial)
void mostrarVector4(int* vec, int tam); //(vector pero muestra puntero)



int main()
{
    int numeros[]={3, 5, 2, 4 , 1};
    mostrarVector1(numeros,TAM);
    mostrarVector2(numeros,TAM);
    mostrarVector3(numeros,TAM);
    mostrarVector3(numeros,TAM);


   return 0;
}
    void mostrarVector1(int vec[], int tam)
    {
    printf("\n\nmostrarVector1");
      for(int i=0; i <5 ; i++)
    {
        printf("\nindice = %d\n valor = %d\n",i,vec[i]);
    }

    }

    void mostrarVector2(int vec[], int tam)
    {
        printf("\n\nmostrarVector2");
        for(int i=0; i <5 ; i++)
    {
        printf("\nindice = %d\n valor = %d\n",i,*(vec+i));
    }
    }


    void mostrarVector3(int* vec, int tam)
    {
         printf("\n\nmostrarVector3");
      for(int i=0; i <5 ; i++)
    {
        printf("\nindice = %d\n valor = %d\n",i,vec[i]);
    }

    }

     void mostrarVector4(int* vec, int tam)
    {
    printf("\n\nmostrarVector4");
        for(int i=0; i <5 ; i++)
    {
        printf("\nindice = %d\n valor = %d\n",i,*(vec+i));
    }

    }

    ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
void mostrarCadena(char* cadena);
int main()
{
    char mensaje[] = "hola mundo";
    mostrarCadena(mensaje);
    return 0;
}

void mostrarCadena(char* cadena)
{

        while(*cadena != '\0')
        {
            printf("%c", *cadena);
            cadena++;
        }
}
--------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
   int dia;
   int mes;
   int anno;

}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;

}eEmpleado;

int main()
{
    eEmpleado unEmpleado =

    {1234, "juan",   'm', 3000,{9,12,2018}
    };
    eEmpleado otroEmpleado =

    {5678, "alvaro", 'f', 5500,{06,12,1997}
    };



    eEmpleado* punteroEmpleado;
    punteroEmpleado = &unEmpleado;
    eEmpleado lista[] ={unEmpleado,otroEmpleado};


    for(int i=0;i<2;i++)
    {
        printf("%s\n",(lista+i)->nombre);
    }

    return 0;
}

