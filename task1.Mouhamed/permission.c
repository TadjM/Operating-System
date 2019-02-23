
#include <stdio.h>
#include <unistd.h>
#include <errno.h>


int main (int argc, char* argv[])
{
    char* filepath = argv[1];
    int  returnval;

   // Check file existence
   returnval = access (filepath, F_OK);
   if  (returnval == 0)
     printf ("\n %s exists\n", filepath);
   else {
      if (errno == ENOENT)
          printf ("%s does not exist\n", filepath);
      else if (errno == EACCES)
     printf ("%s is not accessible\n",filepath);
return 0;
}
// Check read access ...
returnval = access (path, R_OK);
    if (returnval == 0)
       printf ("%s is readable\n", path);
    else
       printf ("%s is not readable (access denied)\n", path);

/* Check write access. */
returnval = access (path, W_OK);
    if (returnval == 0)
       printf ("%s is writable\n", path);
    else if (errno == EACCES)
       printf ("%s is not writable (access denied)\n", path);
    else if (errno == EROFS)
       printf ("%s is not writable (read-only filesystem)\n", path);

return 0;
}
