#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

struct application {
    char callStr[99];
    char path[99];
    char name[99];
    int shouldWait;
};

int main(void){

    int input = 0;
    int cpid = 0;
    struct application appArr[] = {{"1. run firefox", "/usr/bin/firefox", "firefox", 0},
                                  {"2. run firefox (and wait)", "/usr/bin/firefox", "firefox", 1},
                                  {"3. run gedit", "/usr/bin/gedit", "gedit", 0},
                                  {"4. run gedit (and wait)", "/usr/bin/gedit", "gedit", 1},
                                  {"5. run gnome‐calculator", "/usr/bin/gnome-calculator", "gnome-calculator", 0},
                                  {"6. run gnome‐calculator (and wait)", "/usr/bin/gnome-calculator", "gnome-calculator", 1},
                                  {"0. exit", "", "exit", 0}};

    for (int i = 0; i < sizeof(appArr)/sizeof(appArr[0]); i++){
        printf("%s\n", appArr[i].callStr);
    }

    printf("Input the selection number : ");
    scanf("%d", &input);

    //if (input == 0) printf("Do you want to terminate all processes launched by this programm? [y/n] (TODO)\n"), break;
    if (input == 0) return 0;
    else if (input > 0 && input < 7) input--, printf("Forking from parent with pid : '%d' ...\n", getpid()), cpid = fork();
    

    if (cpid == 0) {
        printf("Launching app : '%s' with pid '%d'\n", appArr[input].name, getpid());
        execl(appArr[input].path, appArr[input].name, NULL);
    }
    if (appArr[input].shouldWait == 1) printf("Waiting on child process with pid : '%d'\n", cpid), waitpid(cpid, NULL, 0);

    return 0;

}