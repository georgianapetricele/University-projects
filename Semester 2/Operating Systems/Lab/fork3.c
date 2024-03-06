#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc,char** argv)
{

   for(int i=0;i<3;i++)
{
   int pid = fork();
   if(pid == 0)
  {
     printf("C%d\n",i);
     for(int j=0;j<3;j++)
  {
     int pid2 = fork();
     if( pid2 == 0)
     {
       printf("C%d%d\n",i,j);
       exit(0);
     }
  }
     for(int j=0;j<3;j++)
        wait(0);
   exit(0);
  }
   for(int i=0;i<3;i++)
     wait(0);
   return 0;

}

