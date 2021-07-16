#include<stdio.h>
#include <stdlib.h>

int* floor1 (float * a, float * b)
{
    int *d=malloc(sizeof(int));
    float c=(int)((*a)*(*b));
    *d=(int)c;
    if (*d>c)
        *d--;
    return d;
}
int main ()
{
    float a, b;
    scanf ("%f", &a);
    scanf ("%f", &b);
    int *c=floor1(&a,&b);
    printf ("%d",*c);
    return 0;
}

