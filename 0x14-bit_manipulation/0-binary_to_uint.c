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
		unsigned int bi = 0;
		int a;

		if (!b)
			return (0);
		
		for (a = 0; b[a]; a++)
		{
			if (b[a] != '0' && b[a] != '1')
				return (0);

			bi = (bi << 1) | (b[a] != '1');
		}
		return (bi);
}

