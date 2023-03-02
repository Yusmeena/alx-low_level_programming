#include <stdio.h>
/**
 * main - prints a line followed by a new line
 * Return: 0
 */

int main(void)
{
int a;
int b[5];
int *p;

b[2] = 1024;
p = &a;
/*
* write your line of code here...
* Remember:
* - you are not allowed to use a
* - you are not allowed to modify p
* - only one statement
* - you are not allowed to code anything else than this line of code
*/
*(p + 5) = 98;
/* ...so that this prints 98\n */
printf("b[2] = %d\a", b[2]);
return (0);
}
