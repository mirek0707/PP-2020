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
struct Klient *tablica(char * name, int *n)
{
	FILE *p =fopen(name, "r");
	if(!p)
    {
      puts("ERR1");
      exit(EXIT_FAILURE);
    }
    struct Klient *T=malloc(sizeof(struct Klient));
    int i=0;
    while (	fscanf(p,"%s", T[i].lname)==1)
	{
		T=realloc(T,(i+1)*sizeof(struct Klient));
	    fscanf(p,"%s", T[i].fname);
	    fscanf(p,"%s", T[i].code);
	    fscanf(p,"%d", &T[i].age);
	    i++;
	}
	fclose(p);
	*n=i;
	return T;
}
int main (int argc, char* argv[])
{
	
	int i, n;
	struct Klient *T=tablica(argv[1], &n);
	FILE *p =fopen("dane.dat", "wb");
	if(!p)
    {
      puts("ERR2");
      exit(EXIT_FAILURE);
    }
	fwrite(T, sizeof(struct Klient), n, p);
	fclose(p);

	p=fopen ("dane.dat", "rb");
	if(!p)
    {
      puts("ERR3");
      exit(EXIT_FAILURE);
    }
	struct Klient *temp;
	temp=malloc(sizeof(struct Klient));
	for (i=0;i<n;i++)
	{
		fread (temp,sizeof(struct Klient), 1, p);
		if (temp->age>=18)
		{
			printf("%s, %s, kod: %s, wiek: %d\n", temp->lname, temp->fname, temp->code, temp->age);
		}
	}
	fclose(p);
	free(temp);
    return 0;
  
}