#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool checkInt(double num){
    int temp = (int)num;
    return (num == temp && num >= 1);
}

int main(int argc, char *argv[]){
    srand(time(NULL));

    double size = argc == 2 ? strtod(argv[1], NULL) : 0;

    if (size == 0) {
        while (1) {
            printf("Please input the desired Array size : ");
            scanf("%lf", &size);
            if (!checkInt(size)) printf("Please input only positive integers greater or equal to 1!\n"); else break;
        }
    }

    double average = 0;
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) exit(1);
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 999;
    }

    for(int i = 0; i < size; i++){
        average += arr[i];
        printf("%d ", arr[i]);
    }
    average /= size;
    printf("\nAverage is : %f\n", average);
    free(arr);
    return 0;

}