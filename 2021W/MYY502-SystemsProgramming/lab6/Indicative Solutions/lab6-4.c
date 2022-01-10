// Endeiktiki Lysi tis Askisis 6.4 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_NUM 15

struct student {
	char *onoma;
	int   am;
	float vathmos;
	struct student *next;
};

typedef struct student student_t;


student_t *create_struct_list(char *onoma[], int am[], float vathmos[])
{
	student_t *temp;  /* Store one student here */
	student_t *head;  /* Create the list */
	int i;

	head = NULL;       /* Empty list */
	for(i=0; i<STUDENT_NUM; i++)
	{
		temp = (student_t *)malloc(sizeof(student_t));  /* Memory for 1 node */
		if (temp == NULL) exit(1);
		temp->onoma = strdup(onoma[i]);
		temp->am = am[i];
		temp->vathmos = vathmos[i];
		
		temp->next = head;                  /* Insert in the front of the list */
		head = temp;
	}
	
	return (head);
}


void show_struct_list(student_t *list)
{
	while (list != NULL)        /* Until there is no other node in the list */
	{
		printf("Onoma: %s, AM: %d, Vathmos: %f\n", list->onoma, list->am, list->vathmos);
		list = list->next;               /* Go to the next node */
	}
}


float compute_average_grade(student_t *list)
{
	float sum = 0.0;

	while (list != NULL)        /* Until there is no other node in the list */
	{
		sum += list->vathmos;
		list = list->next;               /* Go to the next node */
	}
	return (sum /((float)STUDENT_NUM));
}


void print_failed_names(student_t *list)
{
	printf("Kopikan oi eksis mathites:\n");
	/* Search the list for students that have grade less than 10 */
	while (list != NULL)        /* Until there is no other node in the list */
	{
		if(list->vathmos < 10)
		{
			printf("Onoma: %s\n", list->onoma);
		}
		list = list->next;               /* Go to the next node */
	}
}


void change_failed_names(student_t *list)
{
	/* Search the list for students that have grade less than 10 */
	while (list != NULL)        /* Until there is no other node in the list */
	{
		if(list->vathmos < 10)
		{
			/* We must reallocate (name_length + 10 chars) to fit the new name! */
			list->onoma = (char *) realloc(list->onoma, (strlen(list->onoma) + 10)*sizeof(char));
			if (list->onoma == NULL) exit(1);  
			strcat(list->onoma, " (failed)"); /* Concatenate the (failed) */
		}
		list = list->next;               /* Go to the next node */
	}
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
	student_t *head;
	
	head = create_struct_list(onoma, am, vathmos);
	show_struct_list(head);
	print_failed_names(head);
	printf("Average grade =%f\n", compute_average_grade(head));
	change_failed_names(head);
	printf("After changing names...\n");
	print_failed_names(head);

	return 0;
}