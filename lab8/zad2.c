#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int zero(double (*f)(double), double a, double b, double* m_z, double eps)
{
	double fa, fb, x0, f0;
	fa=f(a);
	fb=f(b);
	if (fa==0)
	{
		*m_z=a;
		return 1;
	}
	else if (fb==0)
	{
		*m_z=b;
		return 1;
	}
	else if (fa*fb>0)
	{
		return 0;
	}
	while (fabs(a-b)>eps)
	{
		x0=(a+b)/2;
		f0=f(x0);
		if (fabs(f0)<eps)
		{
			break;
		}
		else
		{
			if (fa*f0<0)
			{
				b=x0;
				fb=f0;
			}
			else
			{
				a=x0;
				fa=f0;
			}
		}
	}
	*m_z=x0;
	return 1;

}
double f(double x)
{
	return (-x*x+3*x+11) ;
}

int main ()
{
	double mz1, mz2, mz3;
	int f1=zero(sin, -1, 1, &mz1, 0.0001);
	if (f1==1)
	{
		printf ("sinus: %f\n", mz1);
	}
	else
	{
		printf("brak miejsc zerowych\n");
	}
	int f2=zero(f, 0, 8, &mz2, 0.0001);
	if (f2==1)
	{
		printf ("f1: %f\n", mz2);
	}
	else
	{
		printf("brak miejsc zerowych\n");
	}
	int f3=zero(f, -1, 1, &mz3, 0.0001);
	if (f3==1)
	{
		printf ("f2: %f\n", mz3);
	}
	else
	{
		printf("brak miejsc zerowych\n");
	}
	return 0;
	
}
