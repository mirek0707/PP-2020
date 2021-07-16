#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int double_cmp(const void *a, const void *b) //komparator dla double
{
   return  *(const  double *)a - *( const  double *)b;
}
int cstring_cmp(const void *a, const void *b) //komparator dla stringow
{
   return  strcmp(*(const char **)a,*(const char **)b);
}



int main(int argc, char *argv[])
{
	char *strings[] = { "Alex", "Bill","Bill","Celine", "Dexter", "Forest","Forest","Garcia","Garcia","Garcia", "Pedro","Zorro"};
	double numbers[] = {1.34, 1.34, 4.34, 5.55, 5.67, 5.67, 5.67, 7.76, 8.1, 8.1, 9.12, 11.23};
	int ln=1, ls=1,i;
   char *s=argv[1];       
   double n=atof(argv[2]);

   char ** wsk=(char**)bsearch(&s, strings, sizeof(strings)/sizeof(*strings), sizeof(*strings), cstring_cmp);

   double *num=(double*)bsearch(&n, numbers, sizeof(numbers)/sizeof(*numbers), sizeof(*numbers), double_cmp);

   if(wsk == NULL)
      puts("Lancucha nie ma w tablicy\n");
    else 
    {
    	printf("Lancuch jest w tablicy strings na pozycji %ld\n", wsk - strings);
    	i=1;
    	while (*(wsk+i)==*wsk)
    	{
    		ls++;
    		i++;
    	}
    	i=1;
    	while (*(wsk-i)==*wsk)
    	{
    		ls++;
    		i++;
    	}
    	printf("Ilosc wystapien wynosi: %d\n", ls);
    }        
     

    if(num == NULL)            
      puts("\nLiczby nie ma w tablicy \n");
   else
   {
    	printf("Liczba jest w tablicy numbers na pozycji %ld\n", num - numbers);
    	i=1;
    	while (*(num+i)==n)
    	{
    		ln++;
    		i++;
    	}
    	i=1;
    	while (*(num-i)==n)
    	{
    		ln++;
    		i++;
    	}
    	printf("Ilosc wystapien wynosi: %d\n", ln);
   }
    return 0; 
    
}