#include<stdio.h>
#include<stdlib.h>
void lacz (float *A, float* B, int sa, int sb)
{
    int i=0, j=0, dl=0;
    float *wynik=(float*)malloc(sizeof(float)), n;
    if (wynik==NULL)
            {
                printf("blad przydzielenia pamieci");
                exit(0);
            }
    *wynik=0;
    
    while (i<sa||j<sb)
    {
        if (j==sb)
        {
            n=*(A+i);
            i++;
        }

        else if (i==sa)
        {
            n=*(B+j);
            j++;
        }
        else if (*(A+i)<=*(B+j))
        {
            n=*(A+i);
            i++;
        }
        else if (*(A+i)>*(B+j))
        {
            n=*(B+j);
            j++;
        }
        
        if (dl==0)
        {
            *(wynik)=n;
            dl++;
        }
        else if (n!=*(wynik+dl-1))
        {

            dl++;
            wynik=(float*)realloc(wynik, (dl)*sizeof(float));
            if (wynik==NULL)
            {
                printf("blad przydzielenia pamieci");
                exit(0);
            }
            *(wynik+dl-1)=n;
        }
    }
    for (i=0;i<dl;i++)
    {
        printf ("%.1f ", *(wynik+i));
    }
    free(wynik);
}
int main ()
{
    float arg_1[] = {1.0, 1.2, 1.2, 1.5, 1.5, 1.5, 1.6, 1.6, 1.8, 1.9};
    float arg_2[] = {1.0, 1.1, 1.1, 1.2, 1.4, 1.5, 1.6, 1.6, 1.8, 1.8, 1.8, 1.9, 1.9, 2.0, 2.0};
    int sa=sizeof(arg_1)/sizeof(float), sb=sizeof(arg_2)/sizeof(float);
    lacz (arg_1, arg_2,sa,sb);
    printf("\n");
    return 0;
}
