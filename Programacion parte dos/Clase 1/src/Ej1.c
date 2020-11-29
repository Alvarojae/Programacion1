
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero1;
	int numero2;
	printf("ingrese primer numero =");
	scanf("%d",&numero1);
	printf("ingrese segundo numero =");
	scanf("%d",&numero2);
	printf("el resultado de la resta es=%d",numero1-numero2);
	return EXIT_SUCCESS;
}
