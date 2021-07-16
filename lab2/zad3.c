#include <stdio.h>
#include<string.h>
#include<math.h>
// p - pozycja , n - to liczba bitów
unsigned bity(int x, int p, int n)
{ 
	int i;
	unsigned c=0;
	c=((int)pow(2,n)-1 & (x>>p));
	return c; 
}

void do_binar (int n, char *wsk)
{
	int i, s=sizeof(int)*8;
	for (i=s-1;i>=0;i--, n>>=1)
	{
		wsk[i]=(01 & n)+'0';
	}
	wsk[s]='\0';
}

int main ()
{ 
	unsigned wynik, liczba = 18; // 10010
	char b[sizeof(int)*8+1], b1[4];
	do_binar(liczba,b);
	printf ("%s \n", b);
	wynik = bity(liczba, 1, 3); // 3 bity od pozycji 1, czyli: 1 001 0
	do_binar(wynik, b1);
	printf ("%s \n", b1);
	return 0; 
}
