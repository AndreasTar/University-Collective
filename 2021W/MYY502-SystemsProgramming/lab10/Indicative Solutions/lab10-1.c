/* VVD, 2016 (c)
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>      /* For perror */
#include <fcntl.h>
#include <sys/types.h>


/* The following work on 24bits; 3F = 0011 1111 */
#define PACK3octets(a,b,c)    (((a) << 16) | ((b) << 8) | (c))
#define UNPACKsextet1(x)      (((x) >> 3*6) & 0x3F)
#define UNPACKsextet2(x)      (((x) >> 2*6) & 0x3F)
#define UNPACKsextet3(x)      (((x) >> 1*6) & 0x3F)
#define UNPACKsextet4(x)      ((x)          & 0x3F)


char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "abcdefghijklmnopqrstuvwxyz0123456789+/";


/* 
 * ENCODING
 */
 

/* Stores the encoded data string in the given buffer ("encoded")
 * which is assumed to have enough space.
 */
void base64_encode(unsigned char *data, size_t datalen, char *encoded)
{
	unsigned int p, i, j;

	/* Get all input triplets */
	for (i = j = 0; i+3 <= datalen; i += 3, j += 4)
	{
		p = PACK3octets(data[i+0], data[i+1], data[i+2]);   /* 3 input bytes */
		encoded[j+0] = encoding_table[ UNPACKsextet1(p) ];  /* 4 output chars */
		encoded[j+1] = encoding_table[ UNPACKsextet2(p) ];
		encoded[j+2] = encoding_table[ UNPACKsextet3(p) ];
		encoded[j+3] = encoding_table[ UNPACKsextet4(p) ];
	}
	
	if (i != datalen)       /* Now the last part can have 1 or 2 bytes */
	{
		p = PACK3octets(data[i+0], (i == datalen-2) ? data[i+1] : 0, 0);
		encoded[j+0] = encoding_table[ UNPACKsextet1(p) ];  /* 4 output chars */
		encoded[j+1] = encoding_table[ UNPACKsextet2(p) ];
		encoded[j+2] = (i == datalen-2) ? 
		                  encoding_table[ UNPACKsextet3(p) ] : '=';
		encoded[j+3] = '=';                                 /* Always a padding */
	}
}


/* Returns the size of encoded data string */
int base64_encoding_size(int datalen)
{
	return ( 4 * ((datalen + 2) / 3) );
}


/* Encodes the input binary file onto the output text stream */
void base64_encode_to_stream(int fin, FILE *fout)
{
#define ENCBUFIN  57   /* Multiple of 3 */
#define ENCBUFOUT 76   /* Standard "row" size */
	
	unsigned char bufin[ENCBUFIN];
	char bufout[ENCBUFOUT+1];
	int  nr;
	
	bufout[ENCBUFOUT] = 0;
	while ((nr = read(fin, bufin, ENCBUFIN)) == ENCBUFIN)
	{
		base64_encode(bufin, ENCBUFIN, bufout);
		fprintf(fout, "%s", bufout);   /* Could put \n here */
	}
	if (nr > 0)
	{
		base64_encode(bufin, nr, bufout);
		nr = base64_encoding_size(nr);
		bufout[nr] = 0;
		fprintf(fout, "%s", bufout);   /* Could put \n here */
	}
}


/* 
 * DECODING
 */
 

/* Decodes the input stream directly onto the output stream */
void base64_decode_from_stream(FILE *fin, int fout)
{
}


main(int argc, char *argv[])
{
	char filename[200];
	int  bin;
	FILE *txt;
	
	if (argc >= 3)
	{
		if (strcmp(argv[1], "-d") == 0)
		{
			if ((txt = fopen(argv[2], "r")) == NULL)
				perror("fopen");
			else
			{
				sprintf(filename, "%s.dec64", argv[2]);
				if ((bin = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 
                        S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)) < 0)
					perror("open");
				else
				{
					base64_decode_from_stream(txt, bin);
					fclose(txt);
					close(bin);
					return 0;
				}
			}
		}
		if (strcmp(argv[1], "-e") == 0)
		{
			if ((bin = open(argv[2], O_RDONLY)) < 0)
				perror("open");
			else
			{
				sprintf(filename, "%s.enc64", argv[2]);
				if ((txt = fopen(filename, "w")) == NULL)
					perror("fopen");
				else
				{
					base64_encode_to_stream(bin, txt);
					fclose(txt);
					close(bin);
					return 0;
				}
			}
		}
	}
	fprintf(stderr, "Use -e <file> to encode or -d <file> to decode a file using base 64.\n");
}