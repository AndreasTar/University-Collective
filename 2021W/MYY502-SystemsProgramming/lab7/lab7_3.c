#include <stdio.h>
#include <stdlib.h>

int main(void){

    unsigned int num = 15;
    unsigned int swapped = (num >> 8) | (num << 8);

    for (int i = 8; i <= sizeof(num)-8; i *=4){
        swapped = swapped | (num << i) | (num >> i);
    }
}