#include<stdio.h>
#include<stdlib.h>
#define  MAK_1(n) printf (#n "=%d\n", n)
#define  MAK_2(n)   (!((n)%2)? n>=0? 1:-1  :  0)
int main ()
{
	int x=5, y=9, z=-6;
    MAK_1(7*x+2-y/6);


	printf("%d jest parzyste:%d\n",x, MAK_2(x));
	printf("%d jest parzyste:%d\n",y, MAK_2(y));
	printf("%d jest parzyste:%d\n",z, MAK_2(z));

	return 0;
}