#include <stdio.h>

int *search(int arr[], int size, int num){
    int *t = NULL;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num){
            t = &arr[i];
            return t;
        }
        
    }
    return NULL;
    
}

int main(){

    int mat[10] = {1,2,3,4,5,6,7,8,9,0};
    int *temp = NULL;

    temp = search(mat, 10, 9);
    if (temp != NULL) printf("Index : %ld\nNumber : %d\n", temp-mat, *temp);
    return 0;
}