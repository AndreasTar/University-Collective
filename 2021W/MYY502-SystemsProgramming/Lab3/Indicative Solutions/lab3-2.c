// Endeiktiki Lysi tis Askisis 3.2 

#include <stdio.h>
#define N 10

void search(int array[], int size, int num, int **res);  /* prototype */

int main(void)
{
	/* Arxikopoiw tous pinakes */
	int A[N] = {0, 4, 8, 2, -2, 100, 45, -12, 45, 31};
	int *res;
	
	/* To res prepei na perastei me anafora, ara pernaw ti d/nsi tou */
	search(A, N, 100, &res);
	if (res != NULL)
	{
		printf("Number=%d, position(0-%d)=%ld\n", *res, N-1, res-A);
	}
	else
	{
		printf("Number not found!\n");
	}
	return 0;
}

void search(int array[], int size, int num, int **res)
{
	int i;
	
	for (i=0; i<size; i++)
	{
		if (array[i] == num)
		{
			*res = &(array[i]); /* Otan to vrw epistrefw tin dieuthinsi tou */
			return;
		}
	}
	*res = NULL;
}