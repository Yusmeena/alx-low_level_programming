# include "main.h"

/**
* set_bit - sets the value of a bit to one(1).
* at a given index.
* @n: pointer of an unsigned long int.
* @index: index or position of the bit.
* Return: 1 if it workwd, -1 if it didn't worked.
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int f;

	if (index > 63)
		return (-1);

	f = 1 << index;
	*n = (*n | f);

	return (1);
}
