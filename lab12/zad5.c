#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rand_f(float min, float max)
{
  float r = (float) rand()/RAND_MAX; 
     return  r*(max - min) + min;
}
float ** matrix(int rows, int col, FILE *fp)
{
    float **T=calloc(rows,sizeof(float*));
    if(T==NULL)
    {
        return NULL;
    }

    rewind(fp);
    int i,j;
    float n;
    for (i=0;i<rows;i++)
    {
        *(T+i)=calloc(col,sizeof(float));
        if(*(T+i)==NULL)
        {
            return NULL;
        }
        for (j = 0; j<col; j++)
        {


            if ((fread(&n, sizeof(float), 1, fp)) !=0)
            {
                T[i][j]=n;
            }
            else
            {
                T[i][j]=0.0;
            }
        }
    }
    return T;
}

int main()
{
    float tab[30];
    int i;
    
    srand(time(0));
    FILE *f_1 = fopen ("dane_1.dat","wb");
    int var;
    printf ("rozmiar = ");
    scanf ("%d", &var);
    for (i=0; i<var; i++)
    	tab[i]=rand_f(0.0, 40.0);
 
 //zapisywanie do pliku binarnego dane_1.dat  zawartosci tablicy tab
    fwrite (tab,sizeof(float),var, f_1);
    fclose(f_1);

    f_1 = fopen ("dane_1.dat","rb");
    float** T1=matrix(3,10,f_1);
    for (i=0;i<3;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%f ", T1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    float** T2=matrix(5,6,f_1);
    for (i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            printf("%f ", T2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 3; ++i)
    {
        free(*(T1+i));
    }
    free (T1);
    for (int i = 0; i < 5; ++i)
    {
        free(*(T2+i));
    }
    free (T2);
    fclose(f_1);
    return 0;
} 