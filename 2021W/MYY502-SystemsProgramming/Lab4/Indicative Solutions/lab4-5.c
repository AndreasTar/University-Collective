// Endeiktiki Lysi tis Askisis 4.5
/* Encryption using the ceasar method.
 * 
 * Assume distance d.
 * A lowercase ASCII character character c is the i-th
 * letter in the English alphabet, where i = c - 'a'.
 * The i-th letter is mapped to the (i+d)%26 letter since
 * there are 26 letters in the English alphabet. This
 * has ASCII code 'a'+(i+d)%26.
 * 
 * To decrypt, we do the reverse procedure and subtract d.
 * Thus an encrypted character e is the i-th english letter,
 * where i = e-'a'. The original was in distance -d, thus
 * equal to (i-d)%26. ***To avoid negative numbers we add 26***,
 * i.e. calculate (26+i-d)%26. Add 'a' and you get the ASCII
 * code of the original letter.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* If c is a letter, it returns the letter in distance dist */
char mapcharacter(char c, int dist)
{
	if (islower(c))
		/* (c - 'a') is the position of letter c in the alphabet (a is 0, b is 1, ...) 
		 * (n + dist) % 26, gives the number dist positions after n (circularly)
		 * If 
		 */
		return ( 'a' + (((c-'a') + dist + 26) % 26) );
	else
		if (isupper(c))
			return ( 'A' + (((c-'A') + dist + 26) % 26) );
		else
			return (c);
}


char *encrypt(char *str, int dist)
{
	char *new, *t;
	
	new = (char *) malloc(strlen(str) + 1);  /* +1 for the \0 */
	if (new == NULL) 
	  exit(1);
	for (t = new; *str != '\0'; str++, t++)
		*t = mapcharacter(*str, dist);
	*t = '\0';
	return (new);
}


void decrypt(char *str, int dist)
{
	for (; *str != '\0'; str++)
		*str = mapcharacter(*str, -dist);
}


int main(int argc, char *argv[])
{
	char *s = NULL;
	int  d = 0;
	
	if (argc != 4)
		exit(1);   /* Don't do anything */
	d = atoi(argv[2]);        /* Distance */
	if (d < 1 || d > 25)
	{
		printf("Distance should be > 0 and < 26\n");
		exit(1);
	}
	if (strcmp(argv[1], "encrypt") == 0)
	{
		s = encrypt(argv[3], d);
		printf("%s\n", s);
		free(s);
	}
	else                      /* Assume it is "decrypt" */
	{
		decrypt(argv[3], d);
		printf("%s\n", argv[3]);
	}
	return 0;
}