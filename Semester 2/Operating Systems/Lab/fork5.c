#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc,char** argv)
{
   int pid = fork();
   if(pid == 0)
   {
     execlp("grep","grep","-E","\\<mere\\>","inputgrep.txt",NULL); //escape for escape
     printf("Child\n);
     exit(0);
   }
   else
   {
   print("Parent\n");
   wait(0);
   }
   return 0;

}




