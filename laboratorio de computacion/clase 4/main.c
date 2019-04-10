#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/** \Estructura1

struct datosPersonales
{
    char nombres[20];
    char apellido[20];
    char calle [20];
    int numero;
};

int main()
{
    struct datosPersonales agenda;
    return 0;
}
*/


/** \Estructura2



struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;

};
int main()
{
    struct datosPersonales agenda;
    strcpy(agenda.nombre, "yanina");
    strcpy(agenda.apellido, "scudero");
    strcpy(agenda.calle, "avenida mitre");
    agenda.numero = 750;

    printf("El nombre es: %s", agenda.nombre);
    printf("\nEl apellido es: %s ", agenda.apellido);
    printf("\nLa calle es: %s %d,", agenda.calle, agenda.numero);
    return 0;
}
*/

/** \estructura3


struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    char calle[20];
    int edad;
    int numero;


};
int main()
{
     struct datosPersonales agenda;


      printf("ingrese el nombre: ");
      gets(agenda.nombre);

      printf("ingrese el apellido: ");
      gets(agenda.apellido);

      printf("ingrese la calle: ");
      gets(agenda.calle);

      fflush(stdin);


      printf("ingrese la edad: ");
      scanf("%d", &agenda.edad);

      printf("ingrese numero de calle: ");
      scanf("%d", &agenda.numero);



       printf("El nombre es: %s", agenda.nombre);
       printf("\nEl apellido es: %s ", agenda.apellido);
       printf("\nLa edad es: %d ", agenda.edad);
       printf("\nLa calle es: %s %d,", agenda.calle, agenda.numero);
       return 0;

}
*/

/** \estructura4

struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    char calle[20];
    int edad;
    int numero;


};
int main()
{
     struct datosPersonales vecAgenda[3];
     int i;

    for(int i=0;i<3;i++)
    {
      fflush(stdin);
      printf("\ningrese el nombre: ");
      gets(vecAgenda[i].nombre);

      printf("ingrese el apellido: ");
      gets(vecAgenda[i].apellido);

      printf("ingrese la calle: ");
      gets(vecAgenda[i].calle);

      fflush(stdin);


      printf("ingrese la edad: ");
      scanf("%d", &vecAgenda[i].edad);

      printf("ingrese numero de calle: ");
      scanf("%d", &vecAgenda[i].numero);

    }



    for(i=0;i<3;i++)
    {
           printf("\nEl nombre es: %s", vecAgenda[i].nombre);
           printf("\nEl apellido es: %s ", vecAgenda[i].apellido);
           printf("\nLa edad es: %d ", vecAgenda[i].edad);
           printf("\nLa calle es: %s %d\n-------------------------", vecAgenda[i].calle, vecAgenda[i].numero);
    }

       return 0;


}

*/

/** \estructura4
*/
struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    char calle[20];
    int edad;
    int numero;


};
int main()
{
     struct datosPersonales vecAgenda[3], vecContactos[3], vecAmigos[3];
     int i;

    for(int i=0;i<3;i++)
    {
      fflush(stdin);
      printf("\ningrese el nombre: ");
      gets(vecAgenda[i].nombre);

      printf("ingrese el apellido: ");
      gets(vecAgenda[i].apellido);

      printf("ingrese la calle: ");
      gets(vecAgenda[i].calle);

      fflush(stdin);


      printf("ingrese la edad: ");
      scanf("%d", &vecAgenda[i].edad);

      printf("ingrese numero de calle: ");
      scanf("%d", &vecAgenda[i].numero);

    }



    for(i=0;i<3;i++)
    {
           printf("\nEl nombre es: %s", vecAgenda[i].nombre);
           printf("\nEl apellido es: %s ", vecAgenda[i].apellido);
           printf("\nLa edad es: %d ", vecAgenda[i].edad);
           printf("\nLa calle es: %s %d\n-------------------------", vecAgenda[i].calle, vecAgenda[i].numero);
    }



    for(i=0;i<3;i++)
    {
        strcpy(vecContactos[i].nombre,vecAgenda[i].nombre);
        strcpy(vecContactos[i].apellido,vecAgenda[i].apellido);
        strcpy(vecContactos[i].calle,vecAgenda[i].calle);
        vecContactos[i].numero=vecAgenda[i].numero;
        printf("\n Nombre %d copiado %s ", i, vecContactos[i].nombre);
        printf("\n Apellido %d copiado %s ", i, vecContactos[i].apellido);
        printf("\n Calle %d copiado %s ", i, vecContactos[i].calle);
        printf("\n numero %d copiado %s ", i, vecContactos[i].numero);

    }

    for(i=0;i<3;i++)
    {
        vecAmigos[i]=vecContactos[i];
        printf("\n amigos/nombres %d amigos copiados %s ", i, vecAmigos[i].nombre);
        printf("\n amigos/apellido %d amigos copiados %s ", i, vecAmigos[i].apellido);
        printf("\n amigos/calle  %d amigos copiados %s ", i, vecAmigos[i].calle);
        printf("\n amigos/numero %d amigos copiados %s ", i, vecAmigos[i].numero);


    }

       return 0;


}








