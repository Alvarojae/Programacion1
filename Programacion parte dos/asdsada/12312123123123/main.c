#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dato;
    int aux=0;
    printf("\ningrese un numero= ");
    scanf("%d",&dato);
    aux=5;


    for(int i = 5; i>=1 ; i--)
    {
      aux= aux * (i-1);
      printf("el aux es =%d\n",aux);
    }


 return 0;
}










