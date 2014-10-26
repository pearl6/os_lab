#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
main()
{
        char *arglist[3];
        
        arglist[0] = (char *)malloc(4*sizeof(char)); strcpy(arglist[0],"cal");
        arglist[1] = (char *)malloc(5*sizeof(char)); strcpy(arglist[1],"2012");
        arglist[2] = NULL;
        /* Call execvp */
        execvp("cal",arglist);
 
    printf("This statement is not executed if execvp succeeds.\n");
}

