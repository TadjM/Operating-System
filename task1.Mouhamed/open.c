#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
 // create and open file
 int fd = open("destination.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

 if (fd == -1)
    errExit("open");

  //close file
 if (close(STDIN_FILENO) == -1) /* Close file descriptor 0 */
   errExit("close");

return 0;
}
