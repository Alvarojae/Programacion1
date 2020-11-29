/*
 ============================================================================
 Name        : archivosasd51.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);
	char cadena[64];
	FILE* fp= fopen("archivo.sarasa","r");
	if(fp!=NULL)
	{
		fscanf(fp,"%[a-zA-Z ]",cadena);
		printf("lei = %s",cadena);
	}
	return EXIT_SUCCESS;
}
	/*
	char* variable = "070";
	FILE* fp= fopen("archivo.sarasa","w");
	if(fp!=NULL)
	{
		//fprintf(); escribo en el archivo
		//fwrite();  escribo en el archivo

		fwrite(variable,sizeof(variable),1,fp);

		fclose(fp);

		/////////////////////////////
	char* variable;
	setbuf(stdout, NULL);
	FILE* fp= fopen("archivo.sarasa","rb");
	if(fp!=NULL)
	{
		fread(variable,sizeof(variable),1,fp);
		printf("nombre=%s \n",variable);
		fclose(fp);

	}
	char cadena[64];
	sprintf(cadena,"flaquito");
	FILE* fp= fopen("prueba.data","wb");
	if(fp!=NULL)
	{
		fwrite(cadena,sizeof(cadena),1,fp);
	}


}
*/
