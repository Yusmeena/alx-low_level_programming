#include "main.h"

/**
 * binary_to_uint- converts binary to number to an
 * unsigned int.
 * *@b: binary
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int bi;
	int leng, base2_two;

	if (!b)
		return (0);

	bi = 0;
	for (leng = 0; b[leng] != '\0'; leng++)

	for (leng--; base2_two = 1; leng >= 0; leng--, base2_two, *= 2)
	{
		if (b[leng] != '0' && b[leng] != '1')
		{
			return (0);
		}
		if (b[leng] & 1)
		{ bi += base2_two;
		}
	}
	return (bi);
}
