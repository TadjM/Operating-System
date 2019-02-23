//Tadjoudine Mouhamed


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <string.h>


void interpret (char *line, char **argv)
{
     while (*line != '\0') {        
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     
          *argv++ = line;         
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;            
     }
     *argv = '\0';                 
}

 
void  main(void)
{
     char  buffer[1024];             
     char  *argv[64];              
     size_t buffsize=1024;
     int status;
     pid_t child_One; 
     
     while (1) {               
          
          // type quit to exit the program.
          printf("Enter the command and arguments or quit: "); 
     	  fgets(buffer, sizeof(buffer), stdin);
	  if (buffer[strlen(buffer)-1] == '\n') buffer[strlen(buffer)-1] = '\0'; 

	  printf("\n");
          interpret (buffer, argv);    // parse the line
          if (strcmp(argv[0], "quit") == 0)
               exit(0); 

	  if ((child_One = fork()) < 0) {              
          printf("!!! ERROR: forking child process failed\n");
          exit(1);
	     }
	     else if (child_One == 0) {                   
		  if (execvp(*argv, argv) < 0) {      
		       printf("!!! ERROR: exec failed\n");
		       exit(1);
		  }
	     }
	     else {                                     
		  while (wait(&status) != child_One); 
		       
	     }
   
   
       }
}


