#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void childSigHandler(int sig){
    printf("ID of the Received Signal: %d\n",sig);
    printf("Parent received signal SIGALRM from Child...\n");

    exit(0);
}

void parentSigHandler(int sig){
    printf("ID of the Received Signal: %d\n",sig);
    printf("Child received signal SIGALRM from Child...\n");

    kill(getppid(),SIGCHLD);
    exit(0);
}

int main ()
{
    int pid;
    pid = fork();
    if(pid){
        signal(SIGCHLD, parentSigHandler);
        sleep(2);
        kill(pid, SIGALRM);
        while(1){
            printf("Parent Waiting...\n");
            sleep(1);
        }
        exit(0);
    }
    else{                                                
        signal(SIGALRM,childSigHandler);
        while(1){ 
            printf("Child waiting.....\n");
            sleep(1);
        }
        exit(0);
    }
    exit(0);
}

