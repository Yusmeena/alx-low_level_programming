#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints buffer
 * @b: buffer
 * @size: size
 * Return: void
 */

void print_buffer(char *d, int size)
{
	int c, b, a;

	c = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (c < size)
	{
		b = size - c < 10 ? size - c : 10;
		printf("%08x: ", c);
		for (a = 0; a < 10; a++)
		{
			if (a < b)
				printf("%02x", *(d + c + a));
			else
				printf("  ");
			if (a % 2)
			{
				printf(" ");
			}
		}
		for (a = 0; a < b; a++)
		{
			int y = *(d + c + a);

			if (y < 32 || y > 132)
			{
				y = '.';
			}
			printf("%c", y);
		}
		printf("\n");
		c += 10;
	}
}
