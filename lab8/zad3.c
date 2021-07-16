#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int double_cmp(const void *a, const void *b) //komparator dla double
{
	 return  *(const  double *)a - *( const  double *)b;
}
int cstring_cmp(const void *a, const void *b) //komparator dla stringow
{
	 return  strcmp(*(const char **)a,*(const char **)b);
}
int tabchars_cmp(const void *a, const void *b) //komparator dla tablicy napisow
{
	return  strcmp((const char *)a,(const char *)b);
}

void print_double_array(double*T,int n) //wypisywanie tablicy double
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("%.2f ", T[i]);	
	}
	printf("\n");
}
void print_cstring_array(char**T,int n) //wypisywanie tablicy string'ow
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("%s ", T[i]);	
	}
	printf("\n");
}
void print_tabchars_array(char(*T) [10],int n)  //wypisywanie tablicy napisow 
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("%s ", T[i]);	
	}
	printf("\n");
}
void sort_double_example() //sortowanie tablicy double
{
	double numbers[] = { 7.4, 1.3, 14.5, 0.1, -1.0, 2.3, 1,2, 43.0, 2.0, -4.7, 5.8 };
	size_t numbers_len =sizeof(numbers)/sizeof(double); //okreslenie dlugosci tablicy
	puts("*** Double sorting...");
	print_double_array(numbers, numbers_len); //wypisanie tablicy double przed sortowaniem
	qsort(numbers, numbers_len,sizeof(double), double_cmp); //sortowanie tablicy double funkcja qsort

	print_double_array(numbers, numbers_len); //wypisanie tablicy double po sortowaniu
}

void sort_cstrings_example() //sortowanie tablicy stringow
{
	char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
	size_t strings_len =sizeof(strings)/sizeof(char*); //okreslenie dlugosci tablicy

	puts("*** String sorting...");
	print_cstring_array(strings, strings_len); //wypisanie tablicy stringow przed sortowaniem

	qsort(strings, strings_len, sizeof(char*), cstring_cmp); //sortowanie tablicy stringow funkcja qsort

	print_cstring_array(strings, strings_len); //wypisanie tablicy stringow sortowaniu
}
void sort_tabchars_example() //sortowanie tablicy stringow  
{ char tab_char[][10] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"}; 
  size_t tab_char_N = sizeof(tab_char)/sizeof(tab_char[0]); //okreslenie ilosci napisow w tablicy  
  puts("*** table sorting..."); 
  print_tabchars_array(tab_char, tab_char_N); //wypisanie tablicy napisow przed sortowaniem  
  qsort(tab_char, tab_char_N, sizeof(tab_char[0]), tabchars_cmp); //sortowanie tablicy stringow funkcja qsort
  print_tabchars_array(tab_char, tab_char_N); //wypisanie tablicy napisow sortowaniu 
 } 
// MAIN program (wywołanie funkcji sortujacych)
int main()
{
	sort_double_example();
	sort_cstrings_example();
	sort_tabchars_example();
	return 0;

	
}