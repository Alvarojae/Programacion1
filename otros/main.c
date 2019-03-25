#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dato1;
    int dato2;
    int dato3;
    char dato4;

    printf("ingrese el primer numero ");
    scanf("%d", &dato1);

    printf("ingrese el segundo numero ");
    scanf("%d", &dato2);


    if(dato1==dato2)
    {


        dato1=(char)dato1;
        dato2=(char)dato2;
        dato4=dato1+dato2;
    }else
    {
        if(dato1>dato2)
    {
        dato3=dato1-dato2;
    }else
    {
        dato3=dato1+dato2;
    }
    }

    printf("El resultado es %c", dato4);
    return 0;
}

//concatenan
