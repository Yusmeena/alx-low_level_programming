#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints buffer
 * @b: buffer
 * @size: size
 * Return: void
 */

void print_buffer(char *b, int size)
{
	int s, u, y;

	s = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (s < size)
	{
		u = size - s < 10 ? size - s : 10;
		printf("%08x: ", s);
		for (y = 0; y < 10; y++)
		{
			if (y < u)
				printf("%02x", *(b + s + y));
			else
				printf("  ");
			if (y % 2)
			{
				printf(" ");
			}
		}
		for (y = 0; y < u; y++)
		{
			int c = *(b + s + y);

			if (c < 32 || c > 132)
			{
				c = '.';
			}
			printf("%c", c);
		}
		printf("\n");
		s += 10;
	}
}
