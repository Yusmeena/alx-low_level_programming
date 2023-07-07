#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: unsigned long int input.
 * @index: index of the bit.
 * Return: value of the bit.
 */
int get_bit(unsigbed long int n, unsigbed int index)
{
	unsigned int j;

	if (n == 0 && index < 64)
		return (0);
	for (j = 0; j<= 63; n >== 1, j++)
	{
			if (index == j)
			{
				return(n & 1);
			}
	}

	return (-1);
}
