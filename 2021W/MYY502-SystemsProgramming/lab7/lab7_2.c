#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[]){

    int videoAVI = open(argv[1], "O_RDONLY");
    int data[100];
    int width = 0;
    int height = 0;
    float fps = 0;
    float novf = 0;
    int ts = 0;
    int dr = 0;
    char temp[4];

    lseek(videoAVI, 36, "SEEK_CUR");
    read(videoAVI, data, 4);
    lseek(videoAVI, 16, "SEEK_CUR");
    read(videoAVI, data, 32);

    for(int i = 0; i<100; i++){
        printf("%c ", data[i]);
    }
    for (int i = 0; i<4; i++){
        sprintf(temp, "%d", data[i]);
    }


    printf("\n%ls\n", );

    return 0;
}