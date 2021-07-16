#include<stdio.h>
#include<time.h>
#include <stdlib.h>
int suma (int *tab, int len)
{
    int i, ss = 0;
    for (i = 0; i < len; i++)
    ss+= tab[i];
    return ss;
}

void wypisz_i (int *poczatek, int *koniec)
{
    while (poczatek < koniec)
    printf ("%4d", *poczatek++);
    printf ("\n");
    return;
}
void swap(int*a, int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main ()
{
    int i, j, abc[5][4], suma_abc[5]={}, sumapk[5]={}, suma_po_kolumnach;
	time_t czas;
	srand( (unsigned int)time(&czas) );
    for (i=0;i<5;i++)
    {
        for (j=0;j<4;j++)
        {
            abc[i][j]=(-10+(rand()%20));
        }
    }
    printf ("pkt 1\n");
    for (i=0;i<5;i++)
    {
        wypisz_i(abc[i], abc[i]+4);
    }
    printf ("pkt 2\n");
    for (i=0;i<5;i++)
    {
        suma_abc[i]=suma(abc[i],4);
    }
    wypisz_i(suma_abc, suma_abc+5);
    printf ("pkt 3\n");
    int suma_all = suma (abc[0], sizeof(abc)/sizeof(int));
    printf ("suma wszystkich: %d \n", suma_all);
    printf ("pkt 4\n");
    int  abc1[5][5]={};
    for (i=0;i<5;i++)
    {
        for (j=0;j<4;j++)
        {
            abc1[i][j]=abc[i][j];
        }
    }
    for (i=0;i<5;i++)
    {
        for (j=i+1;j<5;j++)
        {

                swap (abc1[i]+j,abc1[j]+i);

        }
    }
    for (i=0;i<5;i++)
    {
        wypisz_i(abc1[i], abc1[i]+5);
    }

    printf ("pkt 5\n");
    for (i=0;i<5;i++)
    {
        for (j=0;j<5;j++)
        {

            if (j<=i)
                printf ("%4d",abc1[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
