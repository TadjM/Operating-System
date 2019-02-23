#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){

//printf("%d \n", getppid());

//parent P
int a=10, b=25, fq=0, fr=0;
  
  fq=fork(); // fork a child - call it Process Q
  // Child successfully forked
  if(fq==0){
     a=a+b;
     //print values of a, b, and process_id

     printf("a = %d, b = %d\n The process ID is %d\n", a, b, getpid());
   
     fr=fork(); // fork another child - call it Process R
     if(fr!=0){
        b=b+20;
        //print values of a, b, and process_id
        printf("a = %d , b = %d\n The process ID is %d\n", a, b, getpid());
     }
     else{
        a=(a*b)+30;
        //print values of a, b, and process_id
         printf("a = %d , b = %d\n The process ID is %d\n", a, b, getpid());
     }
 }
 else{
    b=a+b-5;
    //print values of a, b, and process_id
    printf("a = %d , b = %d\n The process ID is %d\n", a, b, getpid());

 }
}


