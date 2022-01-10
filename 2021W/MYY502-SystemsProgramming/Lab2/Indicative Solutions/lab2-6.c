// Endeiktiki Lysi tis Askisis 2.6

#include <stdio.h>

#define N 100  /* Maximum number of elements */

/* Function Prototypes */
void mergearrays(int *A, int na, int *B, int nb, int *C);
int  readarray(int *arr);


int main(void)
{
	int i, na, nb;
	int A[N], B[N], C[2*N];   /* Give enough space */

	na = readarray(A);        /* Get them from the user */
	nb = readarray(B);

	mergearrays(A, na, B, nb, C);

	for (i = 0; i < na+nb; i++)
		printf("%d ", C[i]);
	printf("\n");

	return 0;
}


void mergearrays(int *A, int na, int *B, int nb, int *C)
{
	int i, j;

	/* At each iteration use the next element of either A or B and advance C */
	for (i = j = 0; i < na && j < nb; C++)
	{
		if (*A < *B)    /* Select the smaller */
		{
			*C = *A;      /* We could "shortcut" as follows: */
			A++;          /*  *C = *(A++);                   */
			i++;
		}
		else
		{
			*C = *B;      /* Same here */
			B++;
			j++;
		}
	}

	/* If there are no more elements of B, copy remaining elements of A */
	if (i < na)
	{
		for ( /* empty */; i < na; i++)
			*(C++) = *(A++);       /* Two shortcuts! */
	}

	/* If there are no more elements of A, copy remaining elements of B */
	if (j < nb)
	{
		for ( /* empty */; j < nb; j++)
			*(C++) = *(B++);
	}
}


/* Read an array and return the number of elements */
int readarray(int *arr)
{
	int i, num;

	/* Make sure num < N */
	do
	{
		printf("Enter number of elements of the array (at most %d): ", N);
		scanf("%d", &num);
	}
	while (num > N);

	printf("Give the %d elements (sorted): ", num);
	for (i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	return num;
}