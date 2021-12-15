#include <stdio.h>

double minmaxavg(double array[], int num, double *min, double *max){
    double temp = 0;
    
    for(int i = 0; i < num; i ++){
        if(array[i] < *min) *min = array[i];
        if(array[i] > *max) *max = array[i];
        temp += array[i];
    }
    return temp/num;
}

int main(){

    double mat[10] = {1,2,3,4,5,6,7,8,9,65555656};
    double min = mat[0];
    double max = mat[0];
    double avg = 0;

    avg = minmaxavg(mat, 10, &min, &max);
    printf("Min : %f\nMax: %f\nAverage : %f\n", min, max, avg);

    return 0;
}