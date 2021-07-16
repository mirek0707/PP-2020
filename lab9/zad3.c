#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Klient
{
	char fname[20];
	char lname[30];
	char code[7];
	int age;

};
int comp(const void *a, const void *b)
{
  struct Klient TA = *(struct Klient *)a;
  struct Klient TB = *(struct Klient *)b;

  int n = strcmp(TA.lname, TB.lname);
	if (n == 0)
	{
		return strcmp(TA.fname, TB.fname);
	}
  return n;
}
int main (int argc, char* argv[])
{
	struct Klient T[6];
	int i;
	for (i=0;i<6;i++)
	{
		
	    scanf("%s", T[i].lname);
	    scanf("%s", T[i].fname);
	    scanf("%s", T[i].code);
	    scanf("%d", &T[i].age);

    	
	}
	qsort(T, 6, sizeof(T[0]), comp);
	for (i = 0; i < 6; i++)
	{
	 	printf("%s, %s, kod: %s, wiek: %d\n", T[i].lname, T[i].fname, T[i].code, T[i].age);
	}

  return 0;
  
}