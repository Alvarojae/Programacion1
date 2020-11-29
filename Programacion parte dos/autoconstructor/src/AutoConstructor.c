#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
void printNewParam(char* typeStruct,char* typeVar,char* name,char* typeVar1,char* name1,char* typeVar2,char* name2,char* typeVar3,char* name3);
void printGet(char* typeStruct,char* typeVar,char* name);
void printSet(char* typeStruct,char* typeVar,char* name);
void printDelete(char* typeStruct);
void printNew(char* typeStruct);
void printProto(char* typeStruct,char* typeVar,char* name,char* typeVar1,char* name1,char* typeVar2,char* name2,char* typeVar3,char* name3);
void printStruct(char* typeStruct,char* typeVar,char* name,char* typeVar1,char* name1,char* typeVar2,char* name2,char* typeVar3,char* name3);
void isChar(char* typeVar,char* name);

int main(void)
{

	/*
	 {
    int idProducto;
    int idCamion;
    int km;
    int tipoDeEntrega;
    char zona[128];
    char nombre[128];
    int costo;
}Envio;

	 */
	setbuf(stdout, NULL);
	char tipo[50]="Ventas";
	//primero
	char tipoCampo1[50]="int";
	char campo1[50]="idVenta";
	//segundo
	char tipoCampo2[50]="int";
	char campo2[50]="estado";
	//tercero
	char tipoCampo3[50]="int";
	char campo3[50]="CantidadAfiches";
	//cuarto
	char tipoCampo4[50]="int";
	char campo4[50]="Zona";



	printStruct(tipo,tipoCampo1,campo1,tipoCampo2,campo2,tipoCampo3,campo3,tipoCampo4,campo4);
	printProto(tipo,tipoCampo1,campo1,tipoCampo2,campo2,tipoCampo3,campo3,tipoCampo4,campo4);

    printNew(tipo);
    printNewParam(tipo,tipoCampo1,campo1,tipoCampo2,campo2,tipoCampo3,campo3,tipoCampo4,campo4);
    printDelete(tipo);

    printSet(tipo,tipoCampo1,campo1);
    printGet(tipo,tipoCampo1,campo1);

    printSet(tipo,tipoCampo2,campo2);
    printGet(tipo,tipoCampo2,campo2);

    printSet(tipo,tipoCampo3,campo3);
    printGet(tipo,tipoCampo3,campo3);

   printSet(tipo,tipoCampo4,campo4);
   printGet(tipo,tipoCampo4,campo4);

}

void isChar(char* typeVar,char* name)
{
	if(strcmp (typeVar,"char*")==0)
		printf("   char %s[148];\n",name);
	else
		printf("   %s %s;\n",typeVar,name);
}
void printStruct(char* typeStruct,char* typeVar,char* name,char* typeVar1,char* name1,char* typeVar2,char* name2,char* typeVar3,char* name3)
{
	printf (" typedef struct\n"
	"{\n");
	isChar(typeVar,name);
	isChar(typeVar1,name1);
	isChar(typeVar2,name2);
	isChar(typeVar3,name3);
	printf ("}%s; \n\n\n\n",typeStruct);
}


void printNewParam(char* typeStruct,char* typeVar,char* name,char* typeVar1,char* name1,char* typeVar2,char* name2,char* typeVar3,char* name3)
{
    printf( "%s* %s_newParametros(%s %s,%s %s,%s %s,%s %s)\n"
            "{ \n"
            "    %s* this = %s_new(); \n"
            "    if(this != NULL)\n"
            "    { \n"
            "	   if( %s_set_%s(this,atoi(%s)) != -1 &&\n"
    		"	       %s_set_%s(this,atoi(%s)) != -1 &&\n"
            "	       %s_set_%s(this,atoi(%s)) != -1 &&\n"
    		"          %s_set_%s(this,atoi(%s)) != -1 ) \n"
            "	   {\n"
            "               return this;\n"
            "	   }\n"
            "    }\n"
            "    return NULL;\n"
"}\n",typeStruct,typeStruct,typeVar,name,typeVar1,name1,typeVar2,name2,typeVar3,name3,typeStruct,typeStruct,typeStruct,name,name,typeStruct,name1,name1,typeStruct,name2,name2,typeStruct,name3,name3);

}


void printDelete(char* typeStruct)
{
    printf("void %s_delete(%s* this)\n"
	"{\n"
	"	free(this);\n"
	"}\n",typeStruct,typeStruct);

}
void printNew(char* typeStruct)
{

    printf("%s* %s_new()\n"
    "{   %s* new =(%s*)malloc(sizeof(%s)); \n"
	"    return new;\n"
    "}\n",typeStruct,typeStruct,typeStruct,typeStruct,typeStruct);

}
void printSet(char* typeStruct,char* typeVar,char* name)
{

     printf("int %s_set_%s(%s* this, %s %s)\n"
			"{\n"
			"	int retorno=-1;\n"
			"	if(this!=NULL && isValid%s)\n"
			"	{\n" ,typeStruct,name,typeStruct,typeVar,name,name);
			if(strcmp(typeVar,"char*")==0)
                printf("            strncpy(this->%s,%s,(int)sizeof(this->%s));\n",name,name,name);
            else
                printf("            this->%s=%s;\n",name,name);
			printf("	    retorno=0;\n"
			"	}\n"
			"	return retorno;"
			"\n}\n");
}
void printGet(char* typeStruct,char* typeVar,char* name)
{
   printf(  " %s %s_get_%s(%s* this)\n"
			"{\n"
			"	if(this!=NULL )\n"
			"	{\n"
            "	    return this->%s;\n"
            "	}else\n"
		   ,typeVar,typeStruct,name,typeStruct,name);
			if(strcmp(typeVar,"char*")==0)
                printf("            return NULL; \n}\n");
			else
                printf("            return -1; \n}\n");
}


void printProto(char* typeStruct,char* typeVar,char* name,char* typeVar1,char* name1,char* typeVar2,char* name2,char* typeVar3,char* name3)
{
	printf("%s* %s_newParametros(%s %s,%s %s,%s %s,%s %s);\n",typeStruct,typeStruct,typeVar,name,typeVar1,name1,typeVar2,name2,typeVar3,name3);
	printf("void %s_delete(%s* this);\n",typeStruct,typeStruct);
	printf("%s* %s_new();\n",typeStruct,typeStruct);
	printf("int %s_set_%s(%s* this, %s %s);\n",typeStruct,name,typeStruct,typeVar,name);
	printf("%s %s_get_%s(%s* this);\n",typeVar,typeStruct,name,typeStruct);

	printf("int %s_set_%s(%s* this, %s %s);\n",typeStruct,name1,typeStruct,typeVar1,name1);
	printf("%s %s_get_%s(%s* this);\n",typeVar1,typeStruct,name1,typeStruct);

	printf("int %s_set_%s(%s* this, %s %s);\n",typeStruct,name2,typeStruct,typeVar2,name2);
	printf("%s %s_get_%s(%s* this);\n",typeVar2,typeStruct,name2,typeStruct);

	printf("int %s_set_%s(%s* this, %s %s);\n",typeStruct,name3,typeStruct,typeVar3,name3);
	printf("%s %s_get_%s(%s* this);\n\n\n",typeVar3,typeStruct,name3,typeStruct);


}





