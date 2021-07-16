#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 100

int main(int argc, char *argv[])
{
	char slowo[S];
	char *wsk, *p, *d;
	int n=0;
	do
	{
		wsk = fgets(slowo, S,stdin);
		if (wsk != NULL && (strstr(wsk, argv[1]) != NULL) )
			{
			  printf ("%s   \n", slowo);
			  
			  	p=strstr(wsk, argv[1]);
			  	while (p!=NULL)
			  	{
			  		n++;
			  		p=strstr(p+1,argv[1]);
			  	}
			  
			}
	}
	while (wsk != NULL);
	printf ("%d\n", n);
	return 0;
}