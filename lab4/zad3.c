#include<stdio.h>
#include<stdlib.h>
void pisz(int *T, int dl, int pietra)
{
    for(int i=0;i<pietra-dl;i++)
    {
        printf("   ");
    }

    for(int i=0;i<dl;i++)
    {
        printf("%6d", *(T+i));
    }

    printf("\n");
}
int sil (int n)
{
    if (n==1||n==0)
    {
        return 1;
    }
    else
    {
        return n*(sil(n-1));
    }
}
int main ()
{
    int m, n, *pas, i, j;
    void *tmp;

    scanf ("%d", &n);
    pas=(int *)malloc(1*sizeof(int));
    if (pas==NULL)
            {
                printf("blad przydzielenia pamieci");
                exit(0);
            }
    for (i=1;i<=n+1;i++)
    {

        if( (tmp = realloc(pas,i*sizeof(int))) == NULL )
        {
            printf("blad przydzielenia pamieci");
            exit(0);
        }
        else
        {
            pas =(int *)tmp;
            for (j=0;j<i;j++)
            {
                *(pas+j)=sil(i-1)/(sil(j)*sil(i-1-j));

            }


                pisz(pas,i,n+1);


        }

    }
    free(pas);

}

