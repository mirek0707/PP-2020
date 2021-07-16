#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rows 6
#define columns 7
void wypisz_i (int *poczatek, int *koniec)
{
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
    return;
}
int main ()
{
    int i;
    int *array_1[rows];
    for (i=0;i<rows;i++)
    {
        *(array_1+i)=(int*)calloc(columns,sizeof(int));
        if (*(array_1+i)==NULL)
        {
            printf("blad przydzielenia pamieci");
            exit(0);
        }
    }
    for (i=0;i<rows;i++)
    {
        wypisz_i(*(array_1+i),*(array_1+i)+columns);
    }
    for (i=0;i<rows;i++)
    {
        free(*(array_1+i));
    }
    
    printf("\n");

    int *array_2[rows];
    *array_2 = (int*)calloc(rows*columns,sizeof(int));
    if (*(array_2)==NULL)
    {
        printf("blad przydzielenia pamieci");
        exit(0);
    }
    for(int i=0;i<rows;i++)
    {
        *(array_2+i)=(*array_2+columns*i);
    }
    for (i=0;i<rows;i++)
    {
        wypisz_i(*(array_2+i),*(array_2+i)+columns);
    }
    free(*array_2);
    printf("\n");

    int (*array_3)[columns];
    array_3=calloc(rows*columns,sizeof(int));
	if (*(array_3)==NULL)
    {
        printf("blad przydzielenia pamieci");
        exit(0);
    }
	for(i = 0;i<rows;i++)
    {
        wypisz_i(*(array_3+i),*(array_3+i)+columns);
    }

	free(array_3);

}
