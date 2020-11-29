#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main()
{
    char nombres[20];
    char nombres1[20];
    char aux[20];




    printf("ingrese el primer nombre= ");
    scanf("%s",nombres);

    printf("\ningrese el segundo nombre= ");
    scanf("%s",nombres1);


    for(int i = 0 ; i< 2-1;i++)
    {
        for(j=i+1;j<2;j++)
        if(strcmp(nombres[],nombres[])==1)
        {
            strcpy(aux,nombres[i]);
            strcpy(nombres[i],nombres1[j]);
            strcpy(nombres1[j],aux);
        }

    }

    printf("\nel primer nombre es =%s",nombres);
    printf("\nel segundo nombre es =%s",nombres1);


    return 0;
}


// 0 si son iguales
// 1 si el primero es mas grande
// -1 si el segundo es mas grande
