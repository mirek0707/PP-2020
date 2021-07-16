#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concat (char *T[], int n)
{
    int i, j, dl=n;
    for (i=0;i<n;i++)
    {
        for (j=0;T[i][j]!='\0';j++)
        {
            dl++;
        }
    }

    char *wynik=calloc(dl,sizeof(char));
    wynik[0]='\0';
    strcat(wynik,T[0]);
    for (i=1;i<n;i++)
    {
        strcat(wynik," ");
        strcat(wynik,T[i]);
    }
    return wynik;

}
int main ()
{
    char *strings[ ] = {"The sun did not shine.","It was too wet to play."," So we sat in the house - ","All that cold, cold, wet day."};

    char *w=concat(strings,4);
    printf("%s", w);
    free(w);
    return 0;
}
