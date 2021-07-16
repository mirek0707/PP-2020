#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
      printf ("%4d", *poczatek++);
    printf ("\n"); return; }
void proc_1 (int tab[], int dl)
{
    int n=3, i,j, m; //n jest iloscia przesuniec
    for (i=0;i<3;i++)
    {
        m=tab[0];
        for (j=1;j<dl;j++)
        {
            tab[j-1]=tab[j];
        }
        tab[j-1]=m;
    }
}
int main ()
{
    int tab_1[5] = {1,2,3,4,5};
    int i, j, dl1=sizeof(tab_1)/sizeof(int);
    proc_1(tab_1, dl1);
    for (i=0;i<1;i++)
    {
        wypisz_i((tab_1),(tab_1)+5);
    }
    printf("\n");
    int tab_2 [4][2] = {{10,11},{12,13},{14,15},{16,17}};
    proc_1(*tab_2, 8);
    for (i=0;i<4;i++)
    {
        wypisz_i(*(tab_2+i),*(tab_2+i)+2);
    }
    printf("\n");

    int **T; 
    T=calloc(5,sizeof(int*));
    T[0] = calloc(3*5,sizeof(int));
    for(i=1;i<5;i++)
    {
        T[i]=T[i-1]+3;
    }
    for(i=0;i<5;i++)
    {
        for(j=0; j<3; j++)
        {
            T[i][j]=i*3+j;
        }
    }
    for(i=0;i<5;i++)
    {
        wypisz_i(*(T+i), *(T+i)+3);
    }
    proc_1(*T, 15);
    printf("\n");
    for(i=0;i<5;i++)
    {
        wypisz_i(*(T+i), *(T+i)+3);
    }
    free(T[0]);
    free(T);
    return 0;
}
