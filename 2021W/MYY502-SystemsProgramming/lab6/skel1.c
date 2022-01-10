/* Skeleton file for LAB6, Problem 2 */

#include <stdio.h>
#include <stdlib.h>

#define STUDENT_NUM 15


struct student {
	/* Add struct fields here */
	char name;
	int am;
	float score;
} Student;


/* Specify return type */
create_struct_list(char names[], int ams[], float scores[]) {

	struct student *students = (Student *)malloc(STUDENT_NUM * sizeof(Student));
	for (int i = 0; i < STUDENT_NUM; i++){
		students[i] = {names[i], ams[i], scores[i]};
}

void show_struct_list(/* Specify Arguments */) {
}

float compute_average_grade(/* Specify Arguments */) {
}

void print_failed_names(/* Specify Arguments */) {
}

void change_failed_names(/* Specify Arguments */) {
}

int main(void) {
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


	/* 
	 * Put your code here
	 */
	
	
	return 0;
}
