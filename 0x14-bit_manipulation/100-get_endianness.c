#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: zero (0) if big endian, one (1) if little endian
 */
int get_endianness(void)
{
	unsigned int y;
	char *b;

	y = 1;
	b = (char *) &y;

	return ((int)*b);
}
