#include <stdio.h>
#include <math.h>

int main(){

    int nums[30] = {0,};
    int listi = 1;
    int loopi = 0;
    char uInput = 0;
    int t;

    printf("\n");

    while(1)
    {
        printf("Input a **SINGLE CHARACTER** : ");
        scanf("%s^[0-9] ", &uInput);
        //printf(&uInput);
        if (uInput == '$' || loopi == 29) break;
        if (uInput == ' ' || uInput == '\0') continue;
        t = uInput-48;
        if (uInput <= 'Z' && uInput >= 'A'){
            uInput = uInput + 32;
            printf("Lower Case : %c\n", uInput);
        }
        else if (uInput <= 'z' && uInput >= 'a'){
            t = uInput - 'a' + 1;
            printf("Index : %d\n", t);
        }
        else if (t < 10 && t >= 0){
            printf("Number : %d + %d\n", t, listi);
            nums[listi++] = t;
            //printf("this %d", uInput-48);
        } 
        else {
            printf("Not Revognized : %c\n", uInput);
        }
        loopi++;      
    }

    for(int j = 1; j < listi; j++){
        printf("%d ", nums[j]);
    }
    printf("\n");

    return 0;
}