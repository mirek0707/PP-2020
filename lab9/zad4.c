#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define eps 2
struct wektor
{
	double x;
	double y;
	double z;
};
struct abc
{
	struct wektor vect;
	double len;
};
double wekt_len (struct wektor vect)
{
	double dl=0;
	dl=pow(vect.x,2)+pow(vect.y,2)+pow(vect.z,2);
	return sqrt(dl);
}
void f_d (struct abc *T, int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		T[i].len=wekt_len(T[i].vect);
	}
}
int double_cmp(const void *a, const void *b) //komparator dla double
{
	struct abc wektorA = *(struct abc*)a;
	struct abc wektorB = *(struct abc*)b;
	return (wektorA.len>wektorB.len)-(wektorA.len<wektorB.len);
}
int main (int argc, char* argv[])
{
	int i, n;
	n=atoi(argv[1]);
	srand(time(NULL));

	struct abc *T = calloc(n, sizeof(struct abc));
	for (i=0;i<n;i++)
	{
		T[i].vect.x=((rand()/(1.0 * RAND_MAX)) *(10));
		T[i].vect.y=((rand()/(1.0 * RAND_MAX)) *(10));
		T[i].vect.z=((rand()/(1.0 * RAND_MAX)) *(10));
	}
	f_d(T,n);
	for (i=0;i<n;i++)
	{
		printf("%d x=%f y=%f z=%f dl=%f\n",i, T[i].vect.x, T[i].vect.y, T[i].vect.z, T[i].len);
	}
	printf("\n");
	qsort(T, n, sizeof(T[0]), double_cmp);
	for (i=0;i<n;i++)
	{
		printf("%d x=%f y=%f z=%f dl=%f\n", i, T[i].vect.x, T[i].vect.y, T[i].vect.z, T[i].len);
	}
	free (T);
	return 0;
	
}