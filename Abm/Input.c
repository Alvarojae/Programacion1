#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int i = 0;

    printf(message);
    scanf("%d", input);

    if (*input < lowLimit || *input > hiLimit)
    {
        printf(eMessage);
        i = -1;
    }
    return i;
}

int getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit)
{
    int i = 0;

    printf(message);
    scanf("%f", input);

    if (*input < lowLimit || *input > hiLimit)
    {
        printf(eMessage);
        i = -1;
    }
    return i;
}

int getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit)
{
    int i = 0;

    printf(message);
    scanf("%c", input);

    *input = tolower(*input);

    if (*input < lowLimit || *input > hiLimit)
    {
        printf(eMessage);
        i = -1;
    }

    return i;
}

int getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int i = 0;

    printf(message);
    scanf("%s", input);
    if (strlen(input) < lowLimit || strlen(input) > hiLimit)
    {
        printf(eMessage);
        i = -1;
    }

    return i;
}

