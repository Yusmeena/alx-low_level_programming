#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"
/**
 * op_add - adds 5 functions
 * @x: int x
 * @y: int y
 * Return: sum of x and y
 */
int op_add(int x, int y)
{
	return (x + y);
}
/**
 * op_sub - subtracts
 * @x: int x
 * @y: int y
 * Return: difference
 */
int op_sub(int x, int y)
{
	return (x - y);
}
/**
 * op_mul - multiplies
 * @x: int x
 * @y: int y
 * Return: multipliy
 */
int op_mul(int x, int y)
{
	return (x * y);
}
/**
 * op_div - division
 * @x: int x
 * @y: int y
 * Return: division
 */
int op_div(int x, int y)
{
	return (x / y);
}
/**
 * op_mod - modulos
 * @x: int x
 * @y: int y
 * Return: modulo of ints
 */

int op_mod(int x, int y)
{
	return (x % y);
}
