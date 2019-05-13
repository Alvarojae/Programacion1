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
*/

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
