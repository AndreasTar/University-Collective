
// Endeiktiki Lysi tis Askisis 3.4 

/* credit card checker */

#include <stdio.h>

#define DIGITS 16
int check_card_number(char *str);


int main(int argc, char *argv[])
{
	int i, res;
	
	if (argc < 2)
		printf("please re-run and supply 16-digit credit card numbers\n");
	else
		for (i = 1; i < argc; i++)
		{
			res = check_card_number(argv[i]);
			printf("Card %s is %s\n", argv[i], (res == 1) ? "valid" : "invalid");
		}
	return 0;
}


int check_card_number(char *str)
{
	int i, pos = 1;
	int sum = 0;
	int num_int;
	
	/* Check the characters starting from the last one */
	for (i=DIGITS-1; i>=0; i--, pos++)
	{
		num_int = (int)(*(str+i) - '0');    /* Integer value of character  */
		if (pos % 2 == 0)                    /* If we are in an  even psoition */
		{
			num_int *= 2;                     /* Double the number */
			
			/* Get the sum of its digits:
			 * 5 -> 10 -> 1, 6 -> 12 -> 3, ..., 9 -> 18 -> 9
			 * Basically, just subtract 9 from the two-digit number.
			 */
			if (num_int >= 10)
				num_int = num_int - 9;
		}
		sum += num_int;                     /* Sum the digits */
	}
	
	/* Equivallent to: return ( sum % 10 == 0 ); */
	if (sum % 10 == 0)
		return 1;
	else
		return 0;
}