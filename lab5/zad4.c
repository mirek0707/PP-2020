#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
void wypisz_i (int *poczatek, int *koniec)
{
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
    return;
}
int** create_table(int *w)
{
    int n=0, a, i;
    int **T=calloc(1,sizeof(int*));
    if (T==NULL)
    {
        printf("blad przydzielenia pamieci");
        exit(0);
    }
    *(T)=calloc(4,sizeof(int));
    if (*(T)==NULL)
    {
        printf("blad przydzielenia pamieci");
        exit(0);
    }
    scanf ("%d", &a);
    while(a!=0)
    {

        T[*w][n]=a;
        n++;
        scanf ("%d", &a);
        if (n==4)
        {
            (*w)++;
            T=realloc(T,(*w+1)*sizeof(int*));
            if (T==NULL)
            {
                printf("blad przydzielenia pamieci");
                exit(0);
            }
            *(T+*w)=calloc(4,sizeof(int));
            if (*(T)==NULL)
            {
                printf("blad przydzielenia pamieci");
                exit(0);
            }
            n=0;
        }
    }
    return T;
}
int main()
{
    int w=0;
    int ** T=create_table(&w);
    int i, j;

    for (i=0;i<w+1;i++)
    {
        wypisz_i(T[i], T[i]+4);
    }
    for (i=0;i<w+1;i++)
    {
        free(T[i]);
    }
    free(T);

}
