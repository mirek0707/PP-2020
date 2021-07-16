#include <stdlib.h>
#include <stdio.h>
#define ROW 5
#define COL 4
int rand_int(int a, int b)
{
    return rand() % (b-a+1) + a;
}
int sum (int t[], int len){
 int i;
 int ss = 0.;
  for (i=0; i<len; ss+=t[i++]);
return ss;}

//---------------------------

double avg (int t[], int len){
 double ss = (double)sum(t,len)/len;
 return ss;}
int cmp (const void* a, const void* b)
{
	
	if (avg((int *)a,COL)>=avg((int*)b,COL))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
 int main ()
 {
 	 int TAB[ROW][COL];
 	 int i, j;
 	 for (i=0;i<ROW;i++)
 	 {
 	 	for (j=0;j<COL;j++)
 	 	{
 	 		TAB[i][j]=rand_int(-10,10);
 	 	}
 	 }
 	for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
            printf("%2d ", TAB[i][j]);
        printf("\n");
    }
 	 qsort (TAB[0],ROW,sizeof(TAB[i]),cmp);
 	 printf("\n");
 	for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
            printf("%2d ", TAB[i][j]);
        printf("\n");
    }
 }