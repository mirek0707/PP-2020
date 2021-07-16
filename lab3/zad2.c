#include<stdio.h>
#include<time.h>
#include <stdlib.h>
double suma (double **tab, int n, int d)
{
    int i;
    double ss = 0.0;
    for (i = 0; i < d; i++)
        ss+= *(*(tab+n)+i);
    return ss;
}
double **find_tab(double **TAB, int n)
{
    int i;
    double sumamin=suma(TAB,0,4), s;
    double **index=TAB;
    for (i=1;i<n;i++)
    {
        s=suma(TAB,i,4);
        if (s<sumamin)
        {
            sumamin=s;
            index=TAB+i;
        }
    }
    return index;
}
void swap_new ( double ** a, double **b)
{
    double *temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void wypisz_d (double *poczatek, double *koniec) {
  while (poczatek < koniec)
    printf ("%6.2f", *poczatek++);
  printf ("\n");
  return;}

int main ()
{
    int i,j;
    double **min;
    double T_1[4] = {1.0,3.0, 2.0,1.5};
    double T_2[4] = {1.8, 2.0, 1.2, 3.8};
    double T_3[4] = {5.6, 1.0, 3.3, 3.3};
    double T_4[4] = {1.1, 2.1, -6.5, 1.7};
    double T_5[4] = {6.7, 7.8, 9.1, 1.0};
    double *TAB[5]={T_1,T_2,T_3,T_4,T_5};
    printf ("pkt 1\n");
    for (i = 0; i<sizeof(TAB)/sizeof(*TAB); i++)
    {
       for (j = 0; j<4; j++)
       {
            printf("%.2f ", TAB[i][j]);
       }
        printf ("\n");
    }
    printf ("pkt 2\n");
    double *TABLICA;
    for (i=0;i<sizeof(TAB)/sizeof(*TAB);i++)
    {
        TABLICA=TAB[i];
        wypisz_d(TABLICA,TABLICA+4);
    }
    printf ("pkt 3\n");
    printf ("suma T_4: %.2f\n", suma(TAB,3,4));
    printf ("pkt 4\n");
    min =find_tab(TAB, 5);
    wypisz_d(*min, *min+4);

    printf ("pkt 5\n");
    for (i=0;i<4;i++)
    {
        min =find_tab(TAB+i, 5-i);
        swap_new(TAB+i,min);
    }
    for (i=0;i<sizeof(TAB)/sizeof(*TAB);i++)
    {
        TABLICA=TAB[i];
        wypisz_d(TABLICA,TABLICA+4);
    }
    return 0;
}
