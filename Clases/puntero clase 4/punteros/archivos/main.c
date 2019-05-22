#include <stdio.h>
#include <stdlib.h>

int main (void)
{
FILE *parch;

    if((parch=fopen("banco.dat","rb"))==NULL)
    {

            if((parch=fopen("banco.dat","wb"))==NULL)
            {
                printf("\nEl archivo no puede ser abierto");
                exit (1);
            }

        fclose(parch);
    }
    fprintf(parch*)
return 0;
}
