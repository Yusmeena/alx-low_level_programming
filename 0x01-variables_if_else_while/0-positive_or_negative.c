/*A program to generate 
a positive or negative random number */

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(void)
{
   int n;

  srand(time(0);
    n=rand()-RAND_MAX/2;

if (n > 0)
{
    printf("This is a positive number");
}
    else if (n < 0)
{
     printf("This is a negative number");
}

else: 
{
    printf ("number is equal to zero");
}
    return (0);
}
