#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main ()
{
    int n, i, k;
    scanf("%d", &n);
    double *T;
    T=(double *)malloc(n*sizeof(double));
    if (T==NULL)
    {
        printf("blad przydzielenia pamieci");
        exit(0);
    }
    else
    {
        double  *iter=T;
        time_t czas;
        srand( (unsigned int)time(&czas) );
        for (i=0;i<n;i++)
        {
            *(T+i)=23+((double)(rand()%(341-230))/10.0);
        }
        for (i=0;i<n;i++)
        {
            printf ("%.1f ", *(iter+i));
        }
        scanf("%d", &k);
        void *tmp;
        if( (tmp = realloc(T, k * sizeof(double))) == NULL )
        {
            printf("blad przydzielenia pamieci");
            exit(0);
        }
        else
        {
            T = (double *)tmp;
            if (k>n)
            {
                for (i=n;i<k;i++)
                {
                    *(T+i)=(-20+((float)(rand()%(201-50))/10.0));
                }
            }
            iter=T;
            for (i=0;i<k;i++)
            {
                printf ("%.1f ", *(iter+i));
            }
            free(T);

        }

    }
    return 0;
}

