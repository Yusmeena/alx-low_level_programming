#include "main.h"

/**
* get_endianness - checks endianness
*
* Return: zero (0) if big endian, one (1) is little or small endian
*/
int get_endianness(void)
{
	unsigned int f;
	char *b;

	f = 1;
	b = (char *) &f;

	return ((int)*b);
}
