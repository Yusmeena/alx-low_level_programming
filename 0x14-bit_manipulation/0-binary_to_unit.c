#include "main.h"

/**
 *binary_to_unit - converts a binary number to
 *an unsigned int.
 *@b: binary.
 *
 * *Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
		unsigned int bi;
		int len, base2_two;

		if (!b)
			return (0);
		bi = 0;
		for (len = 0; b[len] != '\0'; len++)
			;
		for (len--, base2_two = 1; len >= 0; len--, base2_two *= 2 )
		{
			if (b[len] != '0' && b[len] != '1')
			{
				return (0);
			}
		}
}
