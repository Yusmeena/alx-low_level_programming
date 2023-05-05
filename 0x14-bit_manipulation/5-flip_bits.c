# include "main.h"

/**
* flip_bits - returns the number of bits you would
* need to flip to get from one number to another.
* @n: number one (1).
* @m: number two (2).
*
* Return: number of bits
*/
unsigned int flip_bits(unsigned long n, unsigned long int m)
{
	unsigned int numbits;

	for (numbits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			numbits++;
	}

	return (numbits);
}
