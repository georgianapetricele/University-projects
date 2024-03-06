                                                                       
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
     exit(0);
   }
}
   for(int i=0;i<3;i++)
{ 
  wait(0);  //paralel program  give them the task and wait at the end
}
   return 0;

}


