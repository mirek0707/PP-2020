#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
int comp1(const void *a, const void *b)
{
    const char *x = a, *y = b;
    int c = tolower(*x), d = tolower(*y);
    if (c==d)
    {
    	if(islower(*x))
        c--;
    	if(islower(*y))
        d--;
    }
    
    if(c<d)
    {
        return -1;
    }
    else if(c>d)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int cstring_cmp(const void *a, const void *b) //komparator dla stringow
{
	 return  strcmp((const char *)a,(const char *)b);
}
int main ()
{
	srand(time(NULL));
	const char  litery[52]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char string [20][16];
	int i, j, dl=strlen(litery);
	for (i=0;i<20;i++)
	{
		for (j=0;j<15;j++)
		{
			string[i][j]=litery[rand() % (dl-1)];	
		}
		string[i][j]='\0';
	}
	for (i=0;i<20;i++)
	{
		printf("%s\n",string[i]);
	}
	printf("\n");
	for (i=0;i<20;i++)
	{
		qsort(string[i],15, sizeof(char), comp1);
	}
	for (i=0;i<20;i++)
	{
		printf("%s\n",string[i]);
	}
	printf("\n");
	qsort(string,20,16*sizeof(char),cstring_cmp);
	for (i=0;i<20;i++)
	{
		printf("%s\n",string[i]);
	}
	printf("\n");
	return 0;
	
}