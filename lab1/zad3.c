#include<stdio.h>
void zamiana(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void odwroc(int *T, int n)
{
	for (int i=0; i<n/2; i++)
	{
		zamiana(T+i,T+n-i-1);
	}
}
void wymien_tablice(int *T1, int *T2, int n)
{
	for (int i=0; i<n; i++)
	{
		zamiana(T1+i, T2+i);
	}
}
int main()
{
	////////////a
	int a=5, b=6;
	printf("a=%d, b=%d\n", a, b);
	zamiana (&a,&b);
	printf("a=%d, b=%d\n\n", a, b);
	////////////b
	int n=6; 
	int T[6]={1,2,3,4,5,6};
	printf("T: ");
	for (int i=0; i<n; i++)
	{
		printf("%d ", T[i]);
	}
	printf("\n");

	odwroc(T, n);
	printf("T: ");
	for (int i=0; i<n; i++)
	{
		printf("%d ", T[i]);
	}
	printf("\n\n");
	///////////c
	int T2[6]={7,8,9,10,11,12};
	printf("T2: ");
	for (int i=0; i<n; i++)
	{
		printf("%d ", T2[i]);
	}
	printf("\n\n");

	wymien_tablice(T, T2, n);
	printf("T: ");
	for (int i=0; i<n; i++)
	{
		printf("%d ", T[i]);
	}
	printf("\n");
	printf("T2: ");
	for (int i=0; i<n; i++)
	{
		printf("%d ", T2[i]);
	}
	printf("\n");
	return 0;
}