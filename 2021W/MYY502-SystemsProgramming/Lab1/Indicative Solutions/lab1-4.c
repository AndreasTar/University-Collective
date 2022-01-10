// Endeiktiki Lysi tis Askisis 1.4 
#include <stdio.h>

/* Paradeigma mh apodekths lyshs diagonal Sudoku
int M[9][9] = {{5,3,4,6,7,8,9,1,2},
               {6,7,2,1,9,5,3,4,8},
               {1,9,8,3,4,2,5,6,7},
               {8,5,9,7,6,1,4,2,3},
               {4,2,6,8,5,3,7,9,1},
               {7,1,3,9,2,4,8,5,6},
               {9,6,1,5,3,7,2,8,4},
               {2,8,7,4,1,9,6,3,5},
               {3,4,5,2,8,6,1,7,9}};
*/
/* Paradeigma apodekths lyshs diagonal Sudoku */
int M[9][9] = {{5,8,1,4,2,7,6,9,3},
               {3,7,4,5,9,6,8,1,2},
               {9,6,2,1,3,8,4,7,5},
               {6,2,9,3,8,5,7,4,1},
               {1,5,7,9,6,4,3,2,8},
               {8,4,3,2,7,1,5,6,9},
               {4,1,8,7,5,2,9,3,6},
               {2,9,5,6,4,3,1,8,7},
               {7,3,6,8,1,9,2,5,4}};


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

	/* Elegxos tou pinaka ws pros kathe grammh - prwtos periorismos */
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

	/* Elegxos tou pinaka ws pros kathe sthlh - deuteros periorismos */
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

	/* Elegxos twn 3x3 pinakwn - tritos periorismos */
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

	/* Elegxos tou pinaka ws pros tis diagwnious */

	// First diagonal
	for (i=0; i<10; i++)
		temp[i] = 0;

	for (j=0; j<9; j++)
	{
		if (temp[matrix[j][j]] == 0)
			temp[matrix[j][j]]++;
		else
			return 1;
	}

	// Second diagonal
	for (i=0; i<10; i++)
		temp[i] = 0;

	for (j=0; j<9; j++)
	{
		if (temp[matrix[j][8-j]] == 0)
			temp[matrix[j][8-j]]++;
		else
			return 1;
	}
	return 0;
}
