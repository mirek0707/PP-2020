#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_tab(int a[][4], int x)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < 4; j++)
            printf ("%3d", a[i][j]);
        printf ("\n");
    }
    return;
}

void wypisz_i (int *poczatek, int *koniec)
{
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
    return;
}
 int (*mn_tab_1 (int A[][3],int B[][4], int x))[4]
 {
    int i, j, k, s, dl=sizeof(*B)/sizeof(int), l=sizeof(*A)/sizeof(int);
    int (*T)[4]=calloc(x*4,sizeof(int));
    if (T==NULL)
    {
        printf("blad przydzielenia pamieci");
        exit(0);
    }
    for (i=0;i<x;i++)
    {
        for (j=0;j<4;j++)
        {
            s=0;
            for (k=0;k<l;k++)
            {
                s+=A[i][k]*B[k][j];
            }
            T[i][j]=s;
        }

    }
    return T;

 }
 int main ()
 {
    int t_A [2][3] = {1,2,3,4,5,6};
    int t_B [3][4] = {1,1,1,1,1,1,1,1,1,1,1,1};
    int (*t_C)[4]; 
    t_C= mn_tab_1 (t_A, t_B, 2);
    print_tab(t_C,2);
    printf("\n");
    for (int i=0;i<2;i++)
    {
        wypisz_i(t_C[i], t_C[i]+4);
    }
    free(t_C);

 }
