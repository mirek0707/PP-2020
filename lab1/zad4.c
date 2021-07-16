#include<stdio.h>
#include<math.h>

float suma (float *t, int n, float* min, float* max, float* srednia, float* min_od, float* max_od)
{
	float suma=0.0;
	*min=*max=*t;
	for(int i=0;i<n;i++)
	{
		suma+=*(t+i);
		if (*min>*(t+i))
			*min=*(t+i);
		if (*max<*(t+i))
			*max=*(t+i);
	}
	*srednia=suma/(float)n;

	*min_od=*max_od=fabs(*srednia-*(t));
	for(int i=0;i<n;i++)
	{
		float temp=fabs(*srednia-*(t+i));
		if (*min_od>temp)
			*min_od=temp;
		if (*max_od<temp)
			*max_od=temp;
	}
	return suma;
}

float suma2 (float *t, int n, float* min, float* max, float* srednia, float* min_od, float* max_od)
{
	float suma=0.0;
	*min=*max=t[0];
	for(int i=0;i<n;i++)
	{
		suma+=t[i];
		if (*min>t[i])
			*min=t[i];
		if (*max<t[i])
			*max=t[i];
	}
	*srednia=suma/(float)n;

	*min_od=*max_od=fabs(*srednia-t[0]);
	for(int i=0;i<n;i++)
	{
		float temp=fabs(*srednia-t[i]);
		if (*min_od>temp)
			*min_od=temp;
		if (*max_od<temp)
			*max_od=temp;
	}
	return suma;
}

int main()
{
	float sum=0.0, min=0.0, max=0.0, srednia=0.0, min_od=0.0, max_od=0.0;
	float T[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8};
	int n=sizeof(T)/sizeof(*T);
	sum=suma(T, n, &min, &max, &srednia, &min_od, &max_od);
	printf("suma = %f\nminimum = %f\nmaksimum = %f\nsrednia = %f\nmaks. odchylenie = %f\nmin. odchylenie = %f\n\n", sum, min, max, srednia, max_od, min_od);

	sum=suma2(T, n, &min, &max, &srednia, &min_od, &max_od);
	printf("suma = %f\nminimum = %f\nmaksimum = %f\nsrednia = %f\nmaks. odchylenie = %f\nmin. odchylenie = %f\n", sum, min, max, srednia, max_od, min_od);
}
