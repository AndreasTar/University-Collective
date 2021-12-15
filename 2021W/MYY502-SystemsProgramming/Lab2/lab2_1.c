#include <stdio.h>


int main(){
    // Version 1

    // int a[10] = {0,2,4,6,8,7,6,4,2,0};
    // int *pa = &a[1], *pb = &a[8], *pc;
    // printf("1. *(a+6) = %d\n", *(a+6)); // Prints a[6] -> 6
    // printf("2. pb - pa = %ld\n", pb-pa); // Prints memory distance between a[8] and a[1] = 7
    // printf("3. pb[1] = %d\n", pb[1]);  // Prints the number one index after pb = a[8] so its a[9] = 0
    // printf("4. &pb[1] = %p\n", &pb[1]); /* For pointers better use %p, not %d */ // Prints memory location of a[9]
    // printf("5. *pa += 3 = %d\n", *pa += 3); // Prints a[1] + 3 = 2+3 = 5
    // printf("6. *(pb -= 3) = %d\n", *(pb -= 3)); // Prints number 3 indexes behind pb = a[8] so a[5] = 7

    // Version 2

    // int a[10] = {0,2,4,6,8,7,6,4,2,0};
    // int *pa = &a[1], *pb = &a[8], *pc;
    // printf("1. *(a+6) = %d\n", *(a+6));
    // printf("2. pb - pa = %ld\n", pb-pa);
    // printf("3. pb[1] = %d\n", pb[1]);
    // printf("4. &pb[1] = %d\n", pb[1]); /* For pointers better use %p, not %d */
    // printf("5. *pa += 3 = %d\n", pa[2]);
    // printf("6. *(pb -= 3) = %p\n", &pa[3]);


    // Version 3

    int a[10] = {0,2,4,6,8,7,6,4,2,0};
    int *pa = &a[1], *pb = &a[8], *pc = &a[0];
    printf("1. *(a+6) = %d\n", *(a+6));
    printf("2. pb - pa = %ld\n", pb-pa);
    printf("3. pb[1] = %d\n", pb[1]);
    printf("4. &pb[1] = %p\n", &pb[1]); /* For pointers better use %p, not %d */
    printf("5. *pa += 3 = %d\n", *pa += 3);
    printf("6. *(pb -= 3) = %d\n", *(pb -= 3));
    printf("7. a[0] = %d\n", pc[0]);

    return 0;
}