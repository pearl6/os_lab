#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>

int main(int argc,char *args[]){
    int i,a,num=0,k,j;
    char s[10],ch;
    strcpy(s,args[argc-1]);
    num = atoi(s);
    num *= num;

    printf("In function square, PID: %d\n", getpid());
    i=0;
    while(num){
        a=num%10;
        s[i++]=a+48;
        num=num/10;
    }
    s[i]='\0';
    k=i;
    for(i=0,j=k-1;i<j;i++,j--){
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }
    strcpy(args[argc-1],s);

    if(strcmp(args[0],"twice")==0)    execvp("./twice",args+1);
    if(strcmp(args[0],"half")==0)      execvp("./half",args+1);
    if(strcmp(args[0],"square")==0)    execvp("./square",args+1);

    printf("Ans: %s\n",args[0]);

    return 0;
}
