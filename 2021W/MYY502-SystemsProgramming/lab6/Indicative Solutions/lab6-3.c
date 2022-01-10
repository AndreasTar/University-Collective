// Endeiktiki Lysi tis Askisis 6.3 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 256

struct student {
	char  onoma[LINE_SIZE];   /* This time we use an array */
	int   am;
	float vathmos;
};

typedef struct student student_t;


student_t *create_struct_table_from_file(FILE *sf, int snum)
{
	int i;
	student_t *table;
	char buff[LINE_SIZE];

	/* Allocate a table of structures */
	table = (student_t *)malloc(snum*sizeof(student_t)); 
	if (table == NULL) exit(1);
	for(i=0; i<snum; i++)
	{
		if (sf == stdin)
			printf("Give name, am and grade for student %d in separate lines:\n", i);
		
		/* Get the name of student */
		fgets(buff, LINE_SIZE, sf);
		buff[strlen(buff) -1] = '\0'; /* Remove '\n' from buff */
		strcpy(table[i].onoma, buff);
		
		/* Get the AM of the student */
		fgets(buff, LINE_SIZE, sf);
		table[i].am = atoi(buff);

		/* Get the grade of the student */
		fgets(buff, LINE_SIZE, sf);
		table[i].vathmos = atof(buff);
	}
	return (table);
}


void show_struct_table(student_t *table, int snum)
{
	int i;
	
	printf("Here are the student data:\n");
	for(i=0; i<snum; i++)
		printf("Onoma: %s, AM: %d, Vathmos: %f\n", table[i].onoma, table[i].am, table[i].vathmos);
}


void write_student_data_to_file(student_t *table, int snum)
{
	int i;
	FILE *sf;

	/* Try to open file with student data for writting */
	sf = fopen("students.txt", "w");
	if (sf == NULL)
	{
		printf("Could not open file \"students.txt\" for writing!\n");
		return;
	}
	
	/* First print number of students to file */
	fprintf(sf, "%d\n", snum);
	
	/* Next Print all the members of struct */
	for(i=0; i<snum; i++)
		fprintf(sf, "%s\n%d\n%f\n", table[i].onoma, table[i].am, table[i].vathmos);
	
	fclose(sf);
}


int main(void)
{
	int student_num;
	FILE *student_file;
	student_t *table;
  
	/* Try to open file with student data for reading */
	student_file = fopen("students.txt", "r");
	if (student_file == NULL)
	{
		/* No such file; we must ask the user */
		printf("Give the number of students: ");
		scanf("%d", &student_num); 
		getc(stdin);         /* consume the \n because fgets() follows */
		table = create_struct_table_from_file(stdin, student_num);
	}
	else
	{
		/* Read student data from the file */
		fscanf(student_file, "%d", &student_num);
		getc(student_file);  /* consume the \n because fgets() follows */
		table = create_struct_table_from_file(student_file, student_num);
		fclose(student_file);
	}
	
	show_struct_table(table, student_num);
	write_student_data_to_file(table, student_num);
	printf("Data saved to file students.txt...\n");
	return 0;
}