// Endeiktiki Lysi tis Askisis 4.3
#include <stdio.h>
#include <string.h>    /* strlen(), strcpy() */
#include <stdlib.h>    /* For malloc() */


/* size_t is similar to long int */
char *my_strndup(char *s, size_t n)
{
	char *new;
	int  slen;

	if (s == NULL)       /* Make sure the user gave valid input */
		return (NULL);
	
	/* We must discover how much space we need and allocate it: 
	 *   1 + the minimum of n and the length of s 
	 */
	slen = strlen(s);
	if (slen < n)
		new = (char *) malloc(slen + 1);
	else
		new = (char *) malloc(n + 1);
	
	if (new == NULL)     /* Check */
		return (NULL);
	
	strncpy(new, s, n);  /* Just copy up to n characters */
	if (slen >= n)       /* We must add the \0 ourselves! (check: man strncpy) */
		new[n] = '\0';
	
	return (new);
}


int main()
{
	char arr[100], *copy;

	printf("Enter a line of text:\n");
	fgets(arr, 100, stdin);
	copy = my_strndup(arr, 10);
	if (copy != NULL)
		printf("Original string: %s\nNew string: %s\n", arr, copy);
	return 0;
}