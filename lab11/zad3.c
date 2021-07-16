#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
typedef struct xyz
{
	char z;
	struct xyz * wsk;
}xyz;

xyz *read(FILE *p)
{
	fseek(p, 0, SEEK_END);
	unsigned s=ftell(p);

	rewind(p);
	xyz *t=calloc(s/sizeof(xyz), sizeof(xyz));
	fread(t, sizeof(xyz), s/sizeof(xyz), p);
	return t;
}

int main ()
{
	xyz a, b,c;
	a.wsk=&b;
	b.wsk=&c;
	c.wsk=&a;

	a.z='a';
	a.wsk->z='b';
	a.wsk->wsk->z='c';

	printf("%c\n", b.wsk->wsk->z);
	printf("%c\n", b.z);
	printf("%c\n", b.wsk->z);

	c.wsk->z=toupper(c.wsk->z);
	c.wsk->wsk->z=toupper(c.wsk->wsk->z);
	c.z=toupper(c.z);

	printf("%c\n", c.wsk->z);
	printf("%c\n", c.wsk->wsk->z);
	printf("%c\n", c.z);

	FILE *p1 =fopen("dane.txt", "w");
	if(!p1)
	{
		exit(EXIT_FAILURE);
	}
	fprintf(p1, "%c, %p\n", a.z, a.wsk);
	fprintf(p1, "%c, %p\n", b.z, b.wsk);
	fprintf(p1, "%c, %p\n", c.z, c.wsk);

	FILE *p2 =fopen("dane.dat", "wb");
	if(!p2)
	{
		exit(EXIT_FAILURE);
	}
	fwrite (&a, sizeof(xyz), 1, p2);
	fwrite (&b, sizeof(xyz), 1, p2);
	fwrite (&c, sizeof(xyz), 1, p2);

	fclose(p1);
	fclose(p2);

	FILE *p=fopen("dane.dat", "rb");

	xyz *t=read(p);
	fseek(p, 0, SEEK_END);
	int r=ftell(p);

	for(int i=0; i<r/sizeof(xyz); i++)
		printf("%c %p\n", t[i].z, t[i].wsk);

	free(t);
	fclose(p);
	return 0;
}