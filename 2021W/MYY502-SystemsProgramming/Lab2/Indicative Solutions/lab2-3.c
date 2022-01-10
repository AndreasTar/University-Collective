// Endeiktiki Lysi tis Askisis 2.3 

#include <stdio.h>

#define N 10

/* Function Prototype */
double minmaxavg(double array[], int num, double *min, double *max);


int main(void)
{
	double array[N] = {0.2, 4.6, 8.4, 2.5, -0.2, 100.2, 45.3, -12.5, 45.77, 31.2};
	double min, max, avg;

	avg = minmaxavg(array, N, &min, &max);
	printf("Average=%.2lf, Minimum=%.2lf, Maximum=%.2lf\n", avg, min, max);
	return 0;
}


double minmaxavg(double array[], int num, double *min, double *max)
{
	/* Arxikopoiw tis metavlites moy me tin prwti thesi toy pinaka */
	int i;
	double sum = array[0];

	*min = array[0];
	*max = array[0];

	/* Psaxnw ton pinaka */
	for (i=1; i<num; i++)
	{
		if (*min > array[i])   /* Gia tin elaxisti timi */
		{
			*min = array[i];
		}
		if (*max < array[i])   /* Gia tin megisti timi */
		{
			*max = array[i];
		}
		sum += array[i];      /* Vriskw kai to athroisma */
	}

	return sum/(double)num; /* Epistrefw ton meso oro */
}