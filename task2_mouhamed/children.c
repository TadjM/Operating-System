#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{ 
    int x = 1;
    int rc = fork();
    while (x < 3){ 
         if (rc == 0){
            printf("I am a child number %d and my pid id : %u\n", x, getpid());
            rc = fork();
         }
         else if(rc< 0){
           perror("error creating child process");
        }
        waitpid(getpid(), NULL, WNOHANG | WUNTRACED);
        ++x;
    }
}
    
