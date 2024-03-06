
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc,char** argv)
{
  int p2a[2],a2b[2],b2p[2],n=7;
  int pid = fork();
   if(pid == 0)
   {
     close(b2p[0]);
close(b2p[1]);
close(a2b[0]);
close(p2[1]);
     exit(0);
   }
   int pid = fork();
   if(pid == 0)
   {
     printf("Child\n");
     exit(0);
   }
   wait(0);
   wait(0);
/*
   int pid = fork();
   if(pid == 0)
   {
     printf("Child\n");
     exit(0);
   }
   else
   {
   print("Parent\n");
   wait(0);
   }
*/
   return 0;
}
