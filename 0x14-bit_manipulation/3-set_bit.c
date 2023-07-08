#include "main.h"
/**
 * set_bit - sets the value of a bit to one(1).
 * at a guven index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 * Return: 1 if it worked, -1 if it did't work.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int y;

	if (index > 63)
		return (-1);
	y = 1 << index;
	*n = (*n | y);

	return (1);
}

