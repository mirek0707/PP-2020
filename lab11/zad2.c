#include<stdio.h>
#include<stdlib.h>
#include <string.h>
void fcopy(FILE * p1, FILE * p2)
{
	unsigned temp;
	while((temp=fgetc(p1))!=EOF)
		fputc(temp, p2);

}
int file_cmp(char * n1, char * n2)
{
	FILE *p1 =fopen(n1, "rb");
	if(!p1)
	{
		exit(EXIT_FAILURE);
	}
	FILE *p2 = fopen(n2, "rb");
	if(!p2)
	{
		fclose(p1);
		exit(EXIT_FAILURE);
	}
	fseek(p1, 0, SEEK_END);
    int s1=ftell(p1);
    fseek(p1, 0, SEEK_SET);
    unsigned* m1=malloc(s1);
    fread(m1, 1, s1, p1);
    
    fseek(p2, 0, SEEK_END);
    int s2 = ftell(p2);
    fseek(p2, 0, SEEK_SET);
    unsigned* m2 = malloc(s2);
    fread(m2, 1, s2, p2);
   
    fclose(p1);
    fclose(p2);
    
    if(s1!=s2) {
        return 1;
    }
    return memcmp(m1, m2, s1) != 0;
}


int main (int argc, char * argv[])
{
	FILE *p1 =fopen(argv[1], "r");
	if(!p1)
	{
		exit(EXIT_FAILURE);
	}
	FILE *p2 = fopen(argv[2], "w");
	if(!p2)
	{
		fclose(p1);
		exit(EXIT_FAILURE);
	}
	printf ("zwrocono: %d\n", file_cmp(argv[1], argv[2]));
	fcopy(p1, p2);
	fclose(p1);
	fclose(p2);
	printf ("zwrocono: %d\n", file_cmp(argv[1], argv[2]));

	
	return 0;
}