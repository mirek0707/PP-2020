#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
void va_cat(char **result,int num, ...)
{
	int i, sl=0;
	

    **result='\0';
	va_list  argptr;
	va_start(argptr , num);
	for(i=0;i<num;i++)
	{
		char* a=va_arg(argptr , char*);
		sl+=strlen(a)+1;
		*result=realloc(*result, (sl)*sizeof(char*));
		if (*result==NULL)
		{
		    printf("blad przydzielenia pamieci");
		    exit(0);
		}
		strcat(*result,a);
		
		strcat(*result," ");
	}
	va_end(argptr);
	
}
int main ()
{
	char * result=calloc(1,sizeof(char));
	
	if (result==NULL)
    {
        printf("blad przydzielenia pamieci");
        exit(0);
    }
	va_cat (&result ,3, "If you never did You should.","These things are fun.", "and Fun is good.");
	printf ("%s\n",result);
	free (result);
	char * result2=calloc(1,sizeof(char));
	
	if (result2==NULL)
    {
        printf("blad przydzielenia pamieci");
        exit(0);
    }
	va_cat (&result2 ,4, "Sometimes ",
       "you will never know ",
       "the value of a moment " ,
       "until it becomes a memory.");
	printf ("%s",result2);
	free (result2);
	return 0;
}