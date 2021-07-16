#include<stdio.h>
void swap(int*a, int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}
int * find_max_wsk (int *p, int *k)
{
	int *m=p;
	for (p+1;p<=k;p++)
	{
		if (*m<*p)
		{
			m=p;
		}
	}
	return m;
}
void sort (int *tab, int n)
{
	int i, *m;
	for (i=0; i<n;i++)
	{
		m=find_max_wsk (tab+i, tab+n-1);
		swap (m, tab+i);
	}
}
int main ()
{
	int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};
	int s=sizeof(tab_A)/sizeof(int), i;
	sort (tab_A, 9);
	sort (tab_A+9,14);
	for (i=0;i<s;i++)
	{
		printf ("%d ",tab_A[i]);
	}
	return 0;
}
