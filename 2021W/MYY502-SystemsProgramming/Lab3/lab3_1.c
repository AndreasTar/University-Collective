#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double doAdd(char *nums[], int size){
    double temp = 0;
    for(int i = 2; i < size; i++){
        temp += atof(nums[i]);
    }
    return temp;
}

double doSub(char *nums[], int size){
    double temp = atof(nums[2]);
    for(int i = 3; i < size; i++){
        temp -= atof(nums[i]);
    }
    return temp;
}

double doMult(char *nums[], int size){
    double temp = 1;
    for(int i = 2; i < size; i++){
        temp *= atof(nums[i]);
    }
    return temp;
}

double doDiv(char *nums[], int size){
    double temp = atof(nums[2]);
    for(int i = 3; i < size; i++){
        temp /= atof(nums[i]);
    }
    return temp;
}

int main(int argc, char *argv[]){
    double res;
    if (argc < 3){
        printf("Please input the sign and enough numbers.\n");
        return 0;
    }

    switch (argv[1][0]){
        case 43:
            res = doAdd(argv, argc);
            break;
        case 45:
            res = doSub(argv, argc);
            break;
        case 120:
            res = doMult(argv, argc);
            break;
        case 47:
            res = doDiv(argv, argc);
            break;
        default:
            printf("Operation not recognised : %s\n", argv[1]);
            return 0;
    }
    printf("Result of operation : '%s' is : %f\n", argv[1], res);
    return 0;
}