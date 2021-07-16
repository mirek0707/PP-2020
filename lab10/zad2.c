#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
double sum (double t[], int len){
 int i;
 double ss = 0.;
  for (i=0; i<len; ss+=t[i++]);
return ss;}

//---------------------------

double avg (double t[], int len){
 double ss = sum(t,len)/len;
 return ss;}

//---------------------------

double min (double t[], int len){
 int i;
 int min = 0;
 for (i=0; i<len; i++)
  if (t[i]<t[min]) min=i;
 return t[min];}

//---------------------------

double max (double t[], int len)
{
 int i;
 int max = 0;
 for (i=0; i<len; i++)
  if (t[i]>t[max]) max=i;
 return t[max];
}
typedef struct fun 
{
    char * name;
 	double (*funkcja)(double*, int x);

}fun;
fun *fun_tab (double (*T[])(double *, int), char* names[], int n)
{
	fun* tab=calloc (n,sizeof(fun));
	int i;
	for (i=0;i<n;i++)
	{
		fun temp={names[i], T[i]};
        tab[i] = temp;
	}
    return tab;

}

void fun_prn(struct fun* tab, int len_tab, double* t, int len_t)
{
//tab - tablica struktur
//len_tab - długość tablicy tab 
//t - tablica liczb typu double 
//len_t - długość tablicy t
    for (int i=0; i<len_t; i++)
        printf("\t%s --> %f\n", tab[i].name, tab[i].funkcja(t, len_t));

}

double* un_find(struct fun *T_F, int number, double(*d)[4], int len )
{
    double* min = d[0];
    for (int i=1; i<len; i++){
        double fmin = T_F[number].f(min,4);
        double fb = T_F[number].f(d[i],4);
        if(fb<fmin)
        {
            min = d[i];
        }
    }
    return min;
}

int main ()
{
    double (*TAB_FUN[])(double *, int) = {sum, avg, min, max};

	char *names[] = {"sum", "avg", "min", "max"};

	double data[][4] = {{1.3, 1.2, 0.2, 2.3}, {3.4, 1.1, 1.1, 2.1}, {0.4, 0.9, 2.3, 1.3},{2.3, 0.6, 1.1}};
	int var=4;
	fun* wsk_fun = fun_tab(TAB_FUN,names, var);
    for (int i = 0; i<4; i++){
        printf("%d wiersz \n", i);
        fun_prn(wsk_fun, 4, data[i], 4);
    }
}