#include "main.h"

/**
 * clear_bit - the value set  to a bit of zero (0).
 * at a given index.
 * @n: pointer of an unsigned long integer.
 * @index: index of the bit.
 * Return: 1 if it worked, -1 if it didn't worked.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int f;

	if (index > 63)
		return (-1);

	f = 1 << index;

	if (*n & f)
		*n ^= f;

	return (1);
}
