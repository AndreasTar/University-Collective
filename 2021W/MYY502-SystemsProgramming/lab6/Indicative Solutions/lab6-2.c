// Endeiktiki Lysi tis Askisis 6.2 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_NUM 15

struct student {
	char *onoma;         /* We could also use an array with enough chars */
	int   am;
	float vathmos;
};

typedef struct student student_t;


student_t *create_struct_table(char *onoma[], int am[], float vathmos[])
{
	int i;
	student_t *table;

	/* Allocate a table of structures */
	table = (student_t *)malloc(STUDENT_NUM*sizeof(student_t)); 
	if (table == NULL) exit(1);  
	for(i=0; i<STUDENT_NUM; i++)
	{
		table[i].onoma = strdup(onoma[i]);   /* Remember this? */
		table[i].am = am[i];
		table[i].vathmos = vathmos[i];
	}
	return (table);
}


void show_struct_table(student_t *table)
{
	int i;
	
	for(i=0; i<STUDENT_NUM; i++)
		printf("Onoma: %s, AM: %d, Vathmos: %f\n", table[i].onoma, table[i].am, table[i].vathmos);
}


float compute_average_grade(student_t *table)
{
	int i;
	float total_grade = 0.0;
	
	/* Find sum of all grades */
	for(i=0; i<STUDENT_NUM; i++)
		total_grade += table[i].vathmos;
	return (total_grade/((float)STUDENT_NUM));
}


void print_failed_names(student_t *table)
{
	int i;
	
	printf("Kopikan oi eksis mathites:\n");
	
	/* Search the table for students that have grade less than 10 */
	for(i=0; i<STUDENT_NUM; i++)
		if(table[i].vathmos < 10) /* Print... */
			printf("Onoma: %s\n", table[i].onoma);
}


void change_failed_names(student_t *table)
{
	int i;
	
	/* Search the table for students that have grade less than 10 */
	for(i=0; i<STUDENT_NUM; i++)
		if(table[i].vathmos < 10)
		{
			/* We must reallocate (name_length + 10 chars) to fit the new name! */
			table[i].onoma = (char *) realloc(table[i].onoma, (strlen(table[i].onoma) + 10)*sizeof(char));
			if (table[i].onoma == NULL) exit(1);  
			strcat(table[i].onoma, " (failed)"); /* Concatenate the (failed) */
		};
}


int main(void)
{
	char *onoma[] = {
		"Georgios Georgiou", "Vasilios Vasiliou", "Ioanna Ioannidou", 
		"Nikos Nikolaou", "Kiriakos Kiriakidis", "Kwstas Kwstantinidis", 
		"Spyros Spyropoulos", "Dimitris Dimitropoulos", "Dimitra Dimitriadi", 
		"Areti Aretidou", "Ilias Iliopoulos", "Kwstas Kwstoglou",
    "Aimilia Aimilianou", "Xristina Xristopoulou", "Theodoros Theodorou"
	};
	int am[] = {
		120, 122, 142, 130, 156, 132, 145, 133, 131, 140, 141, 150, 155, 134, 146
	};
	float vathmos[] = {
		12, 8.5, 15.5, 20, 7.5, 1, 19.5, 12, 17, 17.5, 15.5, 18, 19, 18, 19
	};
	student_t *table;
	
	table = create_struct_table(onoma, am, vathmos);
	show_struct_table(table);
	print_failed_names(table);
	printf("Average grade =%f\n", compute_average_grade(table));
	change_failed_names(table);
	printf("After changing names...\n");
	print_failed_names(table);

	return 0;
}