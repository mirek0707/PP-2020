#include<stdio.h>
#include<time.h>
#include <stdlib.h>
void swap(float*a, float*b)
{
	float temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}
int Partition (float * A, int p, int r)
{

	float x = *(A+p);
	int i = p - 1;
    	int j = r + 1;
    	while (1)
	{
		do 
		{
			j = j - 1;
		}
		while (*(A+j) < x);
		do 
		{
			i= i + 1;
		}
		while (*(A+i) > x);
		if (i < j)
	    		swap ((A+i),(A+j));
		else 
			return j;
	}
}
void Quicksort(float *A,int p,int r)
{
	int q;
	if (p < r)
	{
		q = Partition(A, p, r);
		Quicksort(A,p,q);
		Quicksort(A,q+1,r);
	}
}   

int main ()
{
	time_t czas;
	srand( (unsigned int)time(&czas) );
	float T[10];
	int i;
	for  (i=0;i<10;i++)
	{
		T[i]=(-1.50+(float)(rand()%700)/100);
	}
	Quicksort (T, 0, 9);
	for (i=0;i<10;i++)
	{
		printf("%2.2f ", T[i]);
	}
}
