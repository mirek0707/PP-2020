#include<stdio.h>
#include<math.h>
int main ()
{
	int i=0, j, n;
	printf ("Podaj liczbe: ");
	scanf ("%d", &n);
	while (1)
	{
		if ((n<0)||(n>100000))
		{
			printf ("Podaj liczbe jeszcze raz:");
			scanf ("%d", &n);
		}
		else
		{
			break;
		}
	}
	int T[n+1];
	for (i=0;i<=n;i++)
	{
		T[i]=0;
	}
	T[0]=T[1]=1;
	for (i=2;i<=sqrt(n);i++)
	{
		if (T[i]==0)
		{
			for (j=i*2;j<=n;j+=i)
			{
				T[j]=1;
			}
		}
	}
	printf ("Liczby pierwsze to: ");
	for (i=0;i<=n;i++)
	{
		if (T[i]==0)
		{
			printf ("%d ", i);
		}
	}
	return 0;
}
