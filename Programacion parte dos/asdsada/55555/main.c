#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dato;
    printf("ingresa un numero =\n");
    scanf("%d",&dato);
    printf("el valor que ve el usuario = %d\n",dato);
    printf("el valor que ve la compu = %x\n",&dato);

    return 0;
}
