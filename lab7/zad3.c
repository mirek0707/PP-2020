#include <stdio.h>
#include <string.h>
#include<stdlib.h>


///funkcja tworz¹ca tablicê niepowtarzaj¹cych siê s³ów z ³añcucha
char** podziel(char *, int *);
///funkcja sortuj¹ca tablicê s³ów
void sort(char **, int);
///funkcja „sklejaj¹ca” s³owa z tablicy (rozdzielane spacjami) w JEDEN ³añcuch
char* sklej(char **, int);

int main(int argc, char *argv[])
{
	

    int n=0;
	char**slowa=podziel(argv[1],&n);
    sort(slowa,n);

    char* wynik=sklej(slowa,n);


    printf("%s\n",wynik );
    free (slowa);
    free (wynik);
	return 0; 
}


char** podziel(char *string, int * n)
{

	char separ[] = " - ,:;.";
	int i, l=1;
	char **slowa;
	slowa=malloc (sizeof(char *));
	char* token;
	if (slowa==NULL)
	{
		printf("blad przydzialu pamieci\n");
		exit(0);
	}
	token = strtok(string,separ);
	while (token != 0) 
	{
		
		for (i=0;i<l-1;i++)
		{
			if (strcmp(slowa[i],token)==0)
			{
				break;
			}
		}
		if (i==l-1)
		{
			*(slowa+l-1)=token;
			l++;
			slowa=realloc (slowa,l*sizeof(char *));
			if (*slowa==NULL)
			{
				printf("blad przydzialu pamieci\n");
				exit(0);
			}
		}

		token = strtok(0,separ);
	}
    *n=l-1;
	return slowa;
}
void sort(char **lan, int n)
{

//potrzebne zmienne lokalne
    int i, j;
    char *temp;
    for (i=0; i<n-1;i++)
        for (j=i+1; j<n; j++)
            if (strcmp(lan[i],lan[j]) > 0)
            {
                temp=lan[i];
                lan[i]=lan[j];
                lan[j]=temp;
            }

}
char* sklej(char **s, int n)
{
    int i=0, dl=0;
    char *wynik=calloc(1,sizeof(char));
    if (wynik==NULL)
    {
        printf("blad przydzialu pamieci\n");
        exit(0);
    }
    wynik[0]='\0';
    for (i=0;i<n;i++)
    {
        dl+=strlen(*(s+i));
        dl+=1;

        wynik=realloc(wynik,(dl)*sizeof(char));
        
        if (wynik==NULL)
        {
            printf("blad przydzialu pamieci\n");
            exit(0);
        }

        strcat (wynik,*(s+i));
        strcat(wynik, " ");

    }
    return wynik;
}