#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string_array(char* s[],int n)//procedura wypisuj¹ca tablicê stringów
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%s\n", s[i]);
    }
}
char * min_string (char *s[], int n) //znajdowanie najmniejszego stringu w sensie leksykalnym w tablicy stringów - zwraca wskaŸnik do minimalnego
{
    int i;
    char *strmin=s[0];
    for (i=1;i<n;i++)
    {
        if (strcmp(strmin,s[i])==1)
        {
            strmin=s[i];
        }
    }
    return strmin;

}
int main()
{
    char * strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
    char *wsk_string;
    size_t strings_len = sizeof(strings)/sizeof(char*); //okreslenie d³ugoœci tablicy strings


    print_string_array(strings, strings_len); //wypisanie tablicy stringów

    wsk_string = min_string(strings,strings_len);//znalezienie najmniejszego stringu w tablicy

    printf("Najmniejszy to: %s\n", wsk_string); //wypisanie najmniejszego stringu
    return 0;

}

