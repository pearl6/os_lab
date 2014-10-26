#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>

int main(int argc,char *args[]){
    args[argc]=NULL;

    printf("In main function, PID: %d\n", getpid());

    if(strcmp(args[1],"twice")==0)     execvp("./twice",args+2);
    if(strcmp(args[1],"half")==0)       execvp("./half",args+2);
    if(strcmp(args[1],"square")==0)     execvp("./square",args+2);

    return 0;
}
