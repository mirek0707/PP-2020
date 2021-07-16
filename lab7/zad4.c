#include <stdio.h>
#include <string.h>

int add2(int *a , int *b)
{
	return *a+*b;
}


int comp2(int *a , int *b)
{
	return *a-*b;
}


int add2_or_comp2 ( int f(int*, int*) , int a , int b)
{
	return f(&a,&b);
}


int main(void)
{
	int a, b;
	puts("Podaj dwie liczby: ");
	scanf("%d",&a);
	scanf("%d",&b);
	printf("suma wynosi: %d \n",add2_or_comp2(add2, a, b));
	printf("roznica wynosi: %d\n",add2_or_comp2(comp2, a, b));

	return 0; 
}
