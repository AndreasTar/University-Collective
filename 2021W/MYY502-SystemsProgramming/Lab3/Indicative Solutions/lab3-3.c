// Endeiktiki Lysi tis Askisis 3.3 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void charstats(char *string);

int stats[26];   /* global, initialized to 0 by default */


int main()
{
	char input[100];
	int  i;

	printf("Enter sentences; terminate by giving a line that begins with ###\n");
	do
	{ 
		fgets(input, 100, stdin);
		if (strncmp(input, "###", 3) != 0)
			charstats(input);
	} while (strncmp(input, "###", 3) != 0);

	for (i = 0; i < 26; i++)
		printf("%c appeared %2d times\n", 'a'+i, stats[i]);

	return 0;
}


void charstats(char *string)
{
	int n;

	while (*string != '\0')
	{
		if (isalpha(*string))
		{
			n = tolower(*string) - 'a';
			stats[n]++;
		}
		string++;
	}
}
