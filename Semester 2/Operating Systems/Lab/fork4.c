

void f(int n)
{
  if(n > 0)
  {
   int pid = fork();
   if( pid == 0)
     {
       printf("Child: %d\n",n);
       f(n-1);
     }
    else
       wait(0);
   }
  exit(0);
}

int main()
{

  f(3);
   //if print after f never executes because of exit
 return 0;
}
