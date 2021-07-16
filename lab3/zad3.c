#include<stdio.h>
void wypelnij(double (*T)[6], int n)
{
    int i, j;
    double s=0.0, *t;
    for (j=0;j<n;j++)
    {
        for (i=0;i<(sizeof(*T)/sizeof(**T));i++)
        {
            //t=T + i * n + j ;
            s+=0.4;
            T[j][i]=s;
        }
    }
}
void wypisz_d (double *poczatek, double *koniec) {
  while (poczatek < koniec)
    printf ("%6.2f", *poczatek++);
  printf ("\n");
  return;}
int main ()
{
    double A_1[8][6], A_2[10][6];
    wypelnij (A_1, 8);
    wypelnij (A_2, 10);
    for (int i=0;i<sizeof(A_1)/sizeof(*A_1);i++)
    {
        double *T=A_1[i];
        wypisz_d(T,T+6);
    }
    printf("\n");
    for (int i=0;i<sizeof(A_2)/sizeof(*A_2);i++)
    {
        double *T=A_2[i];
        wypisz_d(T,T+6);
    }

}
