#include <stdio.h>

int main(){
    
    int numOfAbs;
    float grade1;
    float grade2;
    float gradeExam;

    int abs;
    float be;
    double finalGrade;

    printf("Give the number of Absences: \n");
    scanf("%d", &numOfAbs);
    if (numOfAbs == 0){
        abs = 10;
    }
    else if (numOfAbs == 1){
        abs = 5;
    }
    else abs = 0;
    
    printf("Give the Grade on the first lab: \n");
    scanf("%f", &grade1);
    printf("Give the Grade on the second lab: \n");
    scanf("%f", &grade2);
    
    be = (abs * .2) + (grade1 * .4) + (grade2 * .4);

    if(be < 4.5){
        printf("Failed in Labs.\n");
        return 0;
    }

    printf("Give the Grade on the Final Exam: \n");
    scanf("%f", &gradeExam);

    if (gradeExam < 4.5){
        printf("Failed in Final Exam.\n");
        return 0;
    }

    finalGrade = (be * .5) + (gradeExam * .5);
    printf("Success with Final Grade : %f\n", finalGrade);

    return 0;
}