// Endeiktiki Lysi tis Askisis 1.3 

#include <stdio.h>

/*Paradeigma apodektis lyshs sudoku*/
int M[9][9] = {{5,3,4,6,7,8,9,1,2},
               {6,7,2,1,9,5,3,4,8},
               {1,9,8,3,4,2,5,6,7},
               {8,5,9,7,6,1,4,2,3},
               {4,2,6,8,5,3,7,9,1},
               {7,1,3,9,2,4,8,5,6},
               {9,6,1,5,3,7,2,8,4},
               {2,8,7,4,1,9,6,3,5},
               {3,4,5,2,8,6,1,7,9}};

/*Paradeigma mh apodektis lyshs sudoku
int M[9][9] = {{5,3,4,6,7,8,9,1,2},
               {5,7,2,1,9,5,3,4,8},
               {1,9,8,3,4,2,5,6,7},
               {8,5,9,7,6,1,4,2,3},
               {4,2,6,8,5,3,7,9,1},
               {7,1,3,9,2,4,8,5,6},
               {9,6,1,5,3,7,2,8,4},
               {2,8,7,4,1,9,6,3,5},
               {3,4,5,2,8,6,1,7,9}};
*/


int main(void)
{
	int check_solution(int matrix[9][9]);

	if (check_solution(M) == 0)
		printf("H lysh einai egkyrh\n");
	else
		printf("H lysh den einai egkyrh\n");
	return 0;
}


int check_solution(int matrix[9][9])
{
	int temp[10], i, j, k, l;

	/* Elegxoyme ton pinaka ws pros kathe grammh.
	 * Den prepei na emfanizetai enas arithmos panw apo 1 fora
	 */
	for (j=0; j<9; j++)
	{
		for (i=0; i<10; i++)
			temp[i] = 0;

		for (i=0; i<9; i++)
		{
			if (temp[matrix[j][i]] >= 1)
				return 1;
			else
				temp[matrix[j][i]]++;
		}
	}

	/* Elegxoyme ton pinaka ws pros kathe sthlh.
	 * Den prepei na emfanizetai enas arithmos panw apo 1 fora
	 */
	for (j=0; j<9; j++)
	{
		for (i=0; i<10; i++)
			temp[i] = 0;

		for (i=0; i<9; i++)
		{
			if (temp[matrix[i][j]] >= 1)
				return 1;
			else
				temp[matrix[i][j]]++;
		}
	}

	/* Elegxoyme ton pinaka ws pros kathe 3x3 ypopinaka.
	 * Den prepei na emfanizetai enas arithmos panw apo 1 fora
	 */
	for (l=0; l<3; l++)
	{
		for (k=0; k<3; k++)
		{
			for (i=0; i<10; i++)
				temp[i] = 0;

			for (j=0; j<3; j++)
			{
				for (i=0; i<3; i++)
				{
					if (temp[matrix[j+3*l][i+3*k]] >= 1)
						return 1;
					else
						temp[matrix[j+3*l][i+3*k]]++;
				}
			}
		}
	}

	return 0;
}