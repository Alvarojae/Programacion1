#include <stdio.h>
#include <stdlib.h>


int main()
{
    char seguir = 's';
    char confirma;


    do
    {
        switch(menu())
        {

        case 1:
            printf("\...........\n\n");
            system("pause");
            break;

        case 2:
            printf("\n...........\n\n");
            system("pause");
            break;

        case 3:
            printf("\n...........\n\n");
            system("pause");
            break;

        case 4:
            printf("\n...........\n\n");
            system("pause");
            break;

        case 5:
            printf("\n...........\n\n");
            system("pause");
            break;

        case 6:
            printf("\nDesea salir? s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}
int menu()
{
    int opcion;

    system("cls");
    printf("  ........... ***\n\n");
    printf("1- ...........\n");
    printf("2- ...........\n");
    printf("3- ...........\n");
    printf("4- ...........\n");
    printf("5- ...........\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
