#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define ROZMIAR 81 //maksymalna dlugoœæ ³añcuchów
#define GRAN 20 // maksymalna liczba ³añcuchów
void sortlan(char *lan[], int num); //procedura sortuj¹ca ³ancuchy
int main(void)
{
    char dane[GRAN][ROZMIAR]; //tablica przechowujaca ³añcuchy nie d³uzsze niz ROZMIAR znakow nie wiecej niz GRAN
    char **wsklan=calloc(ROZMIAR*GRAN,sizeof(char *)); //wskaŸnik na tablicê wskaŸników - rozmiar zale¿ny od iloœci wczytanych ³añcuchów
    if (wsklan==NULL)
    {
        printf("blad przydzialu pamieci");
    }
    int licz = 0; //licznik danych wejsciowych
    int k;
    printf("Podaj maksymalnie %d wierszy \n",GRAN);
    printf("Aby zakonczyc, wcisnij Enter na poczatku wiersza.\n");
    while (licz < GRAN && gets(dane[licz]) != NULL && dane[licz][0] != '\0')
    {
        wsklan[licz] = dane[licz]; //ustaw wskaŸniki z tablicy wsklan na ³añcuchy
        licz++;
    }
    puts("\n Wczytano:\n");
    for (k = 0; k < licz; k++)
        puts(wsklan[k]) ; // z u¿yciem identyfikataora wsklan
    sortlan(wsklan, licz); // wyw³oanie procedury sortuj¹cej
    puts("\n Oto uporzadkowana lista:\n");
    for (k = 0; k < licz; k++)
        puts(dane[k]) ; // z u¿yciem identyfikataora dane
    free(*wsklan);
    return 0;
}
// procedura sortuj¹ca
void sortlan(char *lan[], int num)
{

//potrzebne zmienne lokalne
    int i, j;
    char temp[ROZMIAR];
    for (i=0; i<num-1;i++)
        for (j=i+1; j<num; j++)
            if (strcmp(lan[i],lan[j]) > 0)
            {
                strcpy(temp,lan[i]);
                strcpy(lan[i],lan[j]);
                strcpy(lan[j],temp);
            }
            
}
