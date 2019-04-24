#include <stdio.h>
#include <stdlib.h>

int main()
{

    return 0;
}


/*
Puntero
int nro;
int *n;
nro=3
n=&nro;
printf("%d", nro)  (muestra el 3)
printf("%p", n)    (muestra ox100)
printf("%d", *n)   (muestra el 3)

nombre / direccion /  dato
nro    / ox100     /  3
//n      / ox104     /  ox100

*/

/*
int main()
{
    int x, y
    printf("ingrese")
    scanf("%d", &x)
    printf("ingrese")
    scanf("%d", &y)
    muestra(&x, y)
    printf("x:%d  y:%d", x, y)
    return 0

}

void muestra(int *x, int y)
{
    x=Y
    printf("x:%d  y:%d",*x, y)
}
*/



/*

#include <stdio.h>
int factorial(int );
void main(void)
{
int valor,result;
printf("\nIngrese numero:");
scanf("%d",&valor);
result=factorial(valor);
printf("\nEl factorial de %d es %d",valor,result);
}
int factorial(int n)
{
int resp;
if(n==1)
{
    return 1;
}
resp=n* factorial(n-1);
return (resp);
}

*/
