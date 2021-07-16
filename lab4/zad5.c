#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int n, i, u=0, z=0, d=0;
    float *T, *TU, *TD;
    printf ("Podaj ilosc liczb: ");
    scanf("%d", &n);
    T=(float*)malloc(n*sizeof(float));
    if (T==NULL)
            {
                printf("blad przydzielenia pamieci");
                exit(0);
            }
    TU=(float*)malloc(1*sizeof(float));
    if (TU==NULL)
            {
                printf("blad przydzielenia pamieci");
                exit(0);
            }
    TD=(float*)malloc(1*sizeof(float));
    if (TD==NULL)
            {
                printf("blad przydzielenia pamieci");
                exit(0);
            }
    for (i=0;i<n;i++)
    {
        *(T+i)=-1.5+((float)(rand()%(31))/10.0);
        printf("%.1f ", *(T+i));
    }
    printf("\n");
    for (i=0;i<n;i++)
    {
        if (*(T+i)>=0)
        {
            d++;
            TD=(float*)realloc(TD, (d)*sizeof(float));
            if (TD==NULL)
            {
                printf("blad przydzielenia pamieci");
                exit(0);
            }
            *(TD+d-1)=*(T+i);
        }
        else if (*(T+i)<0)
        {
            u++;
            TU=(float*)realloc(TU, (u)*sizeof(float));
            if (TU==NULL)
            {
                printf("blad przydzielenia pamieci");
                exit(0);
            }
            *(TU+u-1)=*(T+i);
        }

    }
    for(i=0;i<u;i++)
    {
        printf("%.1f ", *(TU+i));
    }
    printf("\n");
    for(i=0;i<d;i++)
    {
        printf("%.1f ", *(TD+i));
    }
    free(TU);
    free(TD);
    free(T);
    return 0;
}
