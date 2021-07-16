#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef union value{
	int 	c;
	double  r;
}value;

typedef struct liczba{
	char typ;
	value wart; 
}liczba;
int rand_int(int a, int b)
{
    return rand() % (b-a+1) + a;
}

double rand_double(double a, double b)
{
     return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}
void los(liczba *x)
{
	int p=rand_int(0,1);
	if ( p==1 )	
		x->typ='i';
	else 	
		x->typ='d';

	if ( x->typ=='i' )	
		x->wart.c=rand_int(0,10);
	else	
		x->wart.r=rand_double(0.0, 10.0);
}
void wypisz(liczba *x){
	if ( x->typ=='i' )
			printf("liczba typu int o wartosci %d\n", x->wart.c);
	else	printf("liczba typu double o wartosci %.2f\n",x->wart.r);
}
int comp_liczba( const void *cc , const void * rr )
{
	liczba fc = *(const liczba*) cc ;
	liczba fr = *(const liczba*) rr ;
	if ( fc.typ == 'i'  &&  fr.typ == 'd' ) return -1;
	if ( fc.typ == 'd'  &&  fr.typ == 'i' ) return 1;
	if ( fc.typ == 'i'  &&  fr.typ == 'i' )	
		return ( fr.wart.c > fc.wart.c ) - ( fr.wart.c < fc.wart.c ) ;
	else 
		return ( fc.wart.r > fr.wart.r ) - ( fc.wart.r < fr.wart.r ) ;
}
int main() 
{
	srand(time(0));
	int i;
	liczba *T = malloc(20*sizeof (liczba));
	if ( T == NULL ) 
	{
		printf("blad przydzielenia pamieci");
		exit(0);
	} 

	for (i=0; i<20; i++)
		los( T+i );

	for (i=0; i<20; i++)
		wypisz( T+i );

	printf ("\n");
	qsort (T,20,sizeof(liczba),comp_liczba);
	for (i=0; i<20; i++)
		wypisz( T+i );
	free(T);
   	return 0;

}