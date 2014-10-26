#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
int main()
{
        int i,*a;
        int n=0,sumOdd=0,sumEven=0;
        printf("Enter number of elements: ");
        scanf("%d",&n);
        a = (int*)malloc(n*sizeof(int));
        printf("Enter the elements:\n");
        
        for (i=0 ; i < n; i++) {
            scanf("%d",&a[i]);
        }

        if (fork()==0) {
                /* First Child Process - Adds Odd Number...*/
                for (i=0 ; i < n; i++){
                    if(a[i]&1)  sumOdd += a[i];
                }
                printf("\nSum of Odd Numbers (Added by First Child): %d", sumOdd);
        }
        else {
                if (fork() == 0) {
                    /* Second child process - Adds Even Numbers...*/                
                     for (i=0 ; i < n; i++) {
                        if(a[i]&1)      continue;
                        else            sumEven += a[i];
                     }
                     printf("\nSum of Even Numbers (Added by Second Child): %d\n", sumEven);
                }
        }
    return 0;
}

