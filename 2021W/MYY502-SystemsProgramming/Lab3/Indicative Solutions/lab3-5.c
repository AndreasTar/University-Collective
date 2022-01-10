// Endeiktiki Lysi tis Askisis 3.5 

/* Small dictionary */

#include <stdio.h>
#include <string.h>

#define N 8
#define M 32

int main(void)
{
	/* Initialize the dictionary */
	char *dic[N] = { 
		"Hello",
		"World",
		"This",
		"is",
		"a",
		"very",
		"small",
		"dictionary"
	};
	char user_input[M];
	int i;
	int found;
	
	while (1)
	{
		/* Prompt for input */
		printf("\n\nType a word or \"fin\" to exit program: ");
		/* If we used fgets(), we should remove the trailing \n */
		scanf("%s", user_input);
		
		/* Check for program termination */
		if (strcmp(user_input, "fin") == 0)
			break;
		
		/* Search dictionary for the given word */
		found = 0;
		for (i=0; i<N; i++)
		{
			if (strcmp(user_input, dic[i]) == 0)
			{
				found = 1;
				break;
			}
		}
		
		if (found)
			printf("Word: \"%s\" exists in dictionary\n", user_input);
		else
			printf("Word: \"%s\" DOES NOT exist in dictionary\n", user_input);
	}
	
	return 0;
}