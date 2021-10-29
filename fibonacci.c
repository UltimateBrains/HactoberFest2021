#include <stdio.h>
int fib(int n);
int main(void)
{
   int a;
   printf("input a number: \n");
   scanf("%i",&a);
   printf("fibonacci series is: \n");
   for(int i=0;i<a;i++)
   {
      printf(" %i ",fib(i));
   }
   printf(" \n");

}

int fib(int n)

{   if(n==0)
    {
        return 0;
    }

    if(n==1)
    {
        return 1;
    }

    return fib(n-1)+fib(n-2);
}
