#include<stdio.h>
#include<string.h>
#include<ctype.h>
void swap(char* a, char* b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}

char* zamien(char *string, int dl)
{
	int p=0;
	while(isupper(string[p]))
	{
		p++;
	}
	printf("%d\n", p);
	for (int i=p;i<dl;i++)
	{
		if (isupper(string[i]))
		{
			for(int j=p;j<dl;j++)
			{
				if (islower(string[j]))
				{
					p++;
					swap(string+i, string+j);
				}
				break;
			}
		}
	}
	return string;
}
int main()
{
	char tekst[]="AnGlIa";
	int dl=strlen(tekst);
	printf("%s\n", tekst);
	char *t=zamien(tekst, dl);
	printf("%s\n", t);
	return 0;
}