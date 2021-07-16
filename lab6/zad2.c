#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
      printf ("%4d", *poczatek++);
    printf ("\n"); return; }
void swap(int*a, int*b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}


void swap_tab(int*a, int*b, int n)
{
    int i;
    for (i=0;i<n;i++)    //procedura wymieniaj¹ca zawartoœæ tablic a i b (o tym samym rozmiarze) przy u¿yciu procedury swap
    {
        swap ((a+i),(b+i));// wymieniamy zawartoœæ elementu a[i] z zawartoœci¹ elementu b[i]
    }
    return;
}


void swap_row(int n, int (*a)[n], int x, int y)
{
    swap_tab((*(a+x)),(*(a+y)), n);
    return;
}
int main ()
{
    int tab_1[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4}; //- wymiana wiersza 1 z 3 przy u¿yciu procedury swap_raw
    int i, j;
    //przyklad 1
    for (i=0;i<4;i++)
    {
        wypisz_i(tab_1[i],tab_1[i]+5);
    }
    swap_row(4, tab_1, 1, 3);
    for (i=0;i<4;i++)
    {
        wypisz_i(tab_1[i],tab_1[i]+5);
    }
    printf("\n");
    //przyklad 2
    int tab_11[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4}; //- wymiana wiersza 0 z 3 przy użyciu procedury swap_tab
    for (i=0;i<4;i++)
    {
        wypisz_i(tab_11[i],tab_11[i]+5);
    }
    swap_tab(*(tab_11),*(tab_11+3), 5);
    for (i=0;i<4;i++)
    {
        wypisz_i(tab_11[i],tab_11[i]+5);
    }
     int tab_2 [5][2] = {1,1,2,2,3,3,4,4,5,5};//- wymiana wiersza 0 z 2 przy użyciu procedury swap_raw
    printf("\n");
    //przyklad 3
    for (i=0;i<5;i++)
    {
        wypisz_i(tab_2[i],tab_2[i]+2);
    }
    swap_row(2, tab_2, 0, 2);
    for (i=0;i<5;i++)
    {
        wypisz_i(tab_2[i],tab_2[i]+2);
    }
    printf("\n");
    //przyklad 4
    int tab_22 [5][2] = {1,1,2,2,3,3,4,4,5,5};//- wymiana wiersza 1 z 2 przy użyciu procedury swap_tab
    for (i=0;i<5;i++)
    {
        wypisz_i(tab_22[i],tab_22[i]+2);
    }
    swap_tab(*(tab_22+1),*(tab_22+2), 2);
    for (i=0;i<5;i++)
    {
        wypisz_i(tab_11[i],tab_11[i]+2);
    }
    printf("\n");
    //przyklad 5
    int **tab_3 = malloc( 6*sizeof(int*)); 
    for(i = 0; i < 6; i++) 
        tab_3[i] = malloc(3 * sizeof(int)); 
    for(i = 0; i < 6; i++) 
        for(j = 0; j < 3; j++) 
            tab_3[i][j] = rand() % 21;
    for (i=0;i<6;i++)
    {
        wypisz_i(tab_3[i],tab_3[i]+3);
    }
    swap_tab(*(tab_3+1),*(tab_3+5), 3);
    for (i=0;i<6;i++)
    {
        wypisz_i(tab_3[i],tab_3[i]+3);
    }
    printf("\n");
    //przyklad 6
    int **tab_33= malloc( 6*sizeof(int*)); 
    tab_33[0] = malloc(6*3 * sizeof(int)); 
    for(i = 1; i < 6; i++) 
        tab_33[i] = tab_33[i-1]+3; 

    for(i = 0; i < 6; i++) 
        for(j = 0; j < 3; j++) 
            tab_33[i][j] = rand() % 21;

    for (i=0;i<6;i++)
    {
        wypisz_i(tab_3[i],tab_3[i]+3);
    }
    swap_tab(*(tab_3+2),*(tab_3+4), 3);
    for (i=0;i<6;i++)
    {
        wypisz_i(tab_3[i],tab_3[i]+3);
    }
    for(i=0; i<6; i++)
        free(tab_3[i]);
    free(tab_3);
    free(tab_33[0]);
    free(tab_33);
}

