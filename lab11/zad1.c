#include<stdio.h>
#include<stdlib.h>
double rand_double(double a, double b)
{
    return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}
void print_text_double(char *name)
{
	FILE *p1 =fopen(name, "r");
	if(!p1)
	{
		exit(EXIT_FAILURE);
	}
	double a;
	while ((fscanf(p1, "%lf", &a)) ==1)
	{
		printf("%lf\n",a);
	}
	fclose(p1);

}
void print_bin_double(char *name)
{
	FILE *p1 = fopen(name, "rb");
	if(!p1)
	{
		exit(EXIT_FAILURE);
	}
	double a;
	while ((fread(&a, sizeof(double), 1, p1)) ==1)
	{
		printf("%lf\n",a);
	}
	fclose(p1);
}

int main (int argc, char * argv[])
{
	int n, i;
	printf("podaj rozmiar tablicy: ");
	scanf ("%d", &n);
	double T[n];
	for (i=0;i<n;i++)
	{
		T[i]=rand_double(0,10);
	}
	FILE *p1 =fopen(argv[1], "wb");
	if(!p1)
	{
		exit(EXIT_FAILURE);
	}
	FILE *p2 = fopen(argv[2], "w");
	if(!p2)
	{
		exit(EXIT_FAILURE);
	}
	fwrite (T, sizeof(double), n, p1);
	for (i=0;i<n;i++)
	{
		fprintf(p2, "%lf\n", T[i]);
	}
	fclose(p1);
	fclose(p2);
	
	print_text_double(argv[2]);
	printf("\n");
	print_bin_double(argv[1]);
	printf("\n");

	p1 =fopen(argv[1], "rb");
	if(!p1)
	{
		exit(EXIT_FAILURE);
	}
	p2 = fopen(argv[2], "r");
	if(!p2)
	{
		exit(EXIT_FAILURE);
	}


	fseek(p1 , 0, SEEK_END);
	int s1 = ftell(p1);
	fseek(p2 , 0, SEEK_END);
	int s2 = ftell(p2);
	printf ("plik binarny --%dbajtow \nplik tekstowy --%dbajtow\n", s1, s2);
	printf("\n");
	fclose(p1);
	fclose(p2);

	p1 =fopen(argv[1], "rb");
	if(!p1)
	{
		exit(EXIT_FAILURE);
	}
	p2 =fopen(argv[2], "r");
	if(!p2)
	{
		exit(EXIT_FAILURE);
	}

	double *T1=malloc(sizeof(double));
	int r1=0;
	double a;
	while(fread(&a, 1, sizeof(double), p1))
	{
		r1++;
		T1=realloc(T1, r1*sizeof(double));
        T1[r1-1]=a;
	}
	for (i=0;i<r1;i++)
	{
		printf("%lf\n",T1[i]);
	}
	printf("\n");

	int r2=0;
	double *T2=calloc(1,sizeof(double));
	if ( T2 == NULL ) 
	{
		puts("Error"); 
		exit(1);
	}
	while (fscanf(p2, "%lf\n",&a)==1)
	{
		
		
		T2[r2]=a;
		r2++;
		T2=realloc(T2,(r2+1)*sizeof(double));
		if ( T2 == NULL ) 
		{
			puts("Error"); 
			exit(1);
		}
	}
	for (i=0;i<r2;i++)
	{
		printf("%lf\n",T2[i]);
	}
	printf("\n");
	free (T1);
	free (T2);
	fclose(p1);
	fclose(p2);	

	p1 =fopen(argv[1], "r+b");
	if(!p1)
	{
		exit(EXIT_FAILURE);
	}
	fseek(p1, 0, SEEK_END);
	int dl=ftell(p1)/sizeof(double);
    fseek(p1, 0, SEEK_SET);
    double z=0.0;
    for (int i=0; i<dl; i+=5)
    {
        fseek(p1,i*sizeof(double),SEEK_SET);
        fwrite(&z,sizeof(z),1,p1);
    }
    fclose(p1);
    p1 =fopen(argv[1], "rb");
	if(!p1)
	{
		exit(EXIT_FAILURE);
	}
	double *T3=malloc(sizeof(double));
	r1=0;
	while(fread(&a, 1, sizeof(double), p1))
	{
		r1++;
		T3=realloc(T3, r1*sizeof(double));
        T3[r1-1]=a;
	}
	for (i=0;i<r1;i++)
	{
		printf("%lf\n",T3[i]);
	}
	return 0;
}