// Endeiktiki Lysi tis Askisis 2.5 

#include <stdio.h>

int main(void)
{
	int x = 1;    /* 4 bytes, all are 0 except least significant (which is 1) */
	char *ptr;

	/* Make it point to where x is stored. It actually points to the first of the
	 * 4 bytes occupied by x.
	 * Because &x is an address (pointer) of an int, we cast it as char* so that
	 * the compiler does not complain (ptr should point to a char). The address
	 * is not changed; it is just treated like an address of a char.
	 */
	ptr = (char *) &x;

	/* Now just check what this first byte contains ... */
	printf("Detected format: %s-endian\n", (*ptr == 1) ? "Little" : "Big");

	return 0;
}