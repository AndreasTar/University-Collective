// Endeiktiki Lysi tis Askisis 7.3 

#include <stdio.h>

int reverse_endian(int num);
int reverse_endian_ptrs(int num);

int main(void)
{
	int num = 0xA0B0C0D0;

	printf("Original number: %8X (%d)\n", num, num);
	num = reverse_endian(num);
	printf("Reversed endianess number: %8X (%d)\n", num, num);
	num = reverse_endian_ptrs(num);
	printf("Restored endianess number: %8X (%d)\n", num, num);

	return 0;
}


int reverse_endian(int num)
{
	int b1, b2, b3, b4;

	/* Isolate the 4 bytes */
	b1 = num & 0xFF;             /* = 255 = 11111111b */
	b2 = (num >> 8)  & 0xFF;     /* = 255 = 11111111b */
	b3 = (num >> 16) & 0xFF;     /* = 255 = 11111111b */
	b4 = (num >> 24) & 0xFF;     /* = 255 = 11111111b */

	/* Shift and place the 4 bytes */
	num = b1;                  /* Push b1 */
	num = (num << 8) | b2;     /* Push b2 */
	num = (num << 8) | b3;     /* Push b3 */
	num = (num << 8) | b4;     /* Push b4 */

	return (num);
}


int reverse_endian_ptrs(int num)
{
	char *byte, temp;

	byte = (char *) &num;      /* pointer to 1st byte of num */
	temp = *byte;              /* swap with 4th byte */
	*byte = *(byte+3);
	*(byte+3) = temp;

	temp = *(byte+1);          /* swap with 2nd and 3rd byte */
	*(byte+1) = *(byte+2);
	*(byte+2) = temp;

	return (num);
}
