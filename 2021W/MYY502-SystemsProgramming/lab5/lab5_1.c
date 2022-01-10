#include <stdio.h>
#include <stdlib.h>

int main(void){

    // char *string = 0;
    int count = 0;
    FILE *fpData = fopen("data.txt","r");
    if(fpData == NULL) {
      printf("Error opening file");
      return(-1);
   }

    fscanf(fpData, "%d", &count);
    printf("%d\n", count);

    double *data = (double *)malloc(count * sizeof(double));
    double *negData = (double *)malloc(count * sizeof(double));
    double *posData = (double *)malloc(count * sizeof(double));

    char num = 0;
    int ni = 0;
    int pi = 0;
    while(fscanf(fpData, "%c", &num) != EOF){
        if (num == "\n") continue;
        num = strtod(num, NULL);
        if (num < 0) negData[ni] = num, ni++;
        else posData[pi] = num, pi++;
    }

    FILE *fpPos = fopen("positive.txt", "w");
    FILE *fpNeg = fopen("negative.txt", "w");
    for (int i = 0; i < ni; i++){
        fputs((char *)negData[i], fpNeg);
    }
    for (int i = 0; i < pi; i++){
        fputs((char *)posData[i], fpPos);
    }



    fclose(fpData);
    return 0;


}