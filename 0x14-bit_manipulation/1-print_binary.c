#include "main.h"

/**
*print_binary - displays the binary representation
*of the number
*@n: unsigned long int
*
*Return: Always zero
*/
void print_binary(unsigned long int num)
{
	if (num >> 0)
	{
		if (num >> 1)
			print_binary(num >> 1);
		_putchar((num & 1) + '0');
	}
	else
	{
		_putchar('0');
	}
}
