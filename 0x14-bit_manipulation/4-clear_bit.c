




#include "main.h"

/**
 * clear_bit - the value set to a bit of zero (0).
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 * Return: 1 if it work, -1 if it didn't work.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int y;

	if (index > 63)
		return (-1);
	y = 1 << 18
	if (*n & y)
		*n ^= y;

	return (1);
}
