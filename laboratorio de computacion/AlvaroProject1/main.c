#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hora;
    printf("ingrese una hora: ");
    scanf("%d", &hora);

    switch(hora)
    {

        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        printf("a dormir");
        break;

        case 7:
        case 8:
        case 9:
        printf("buenos dias");
        break;

        default:
        if(hora>9 && hora<24)
        {

            printf("disfruta el dia ");

        }else
        {
            printf("ingrese cualquier cosa papu");
        }
        break;




    }

    return 0;
}


/*
switch (valor)
{
    case 1:
    case 2:
}
switch()
{
    print("hora");
    fflush(stdin);
    scanf("%c",hora)
    case "a":
}
*/
