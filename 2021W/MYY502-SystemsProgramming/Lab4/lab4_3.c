#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strndup(const char *s, int n){

    char *ns = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n && s[i] != '\0'; i++) ns[i] = s[i];
    ns[n] = '\0';
    return ns;

}

int main(){

    char* string;
    int size = 0;
    printf("Input String : ");
    fgets(string, 99, stdin);
    printf("Input how many characters to copy : ");
    scanf("%d", &size);
    char* newString = my_strndup(string, size);
    printf("\nOriginal String : %s\nNew String : %s\n", string, newString);

    return 0;
}