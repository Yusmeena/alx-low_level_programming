#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints diagonal summaries
 * @a: array to use
 * @size: size of diagonal
 */
void print_diagsums(int *a, int size)
{
	int y;
	int diagO = 0;
	int diagT = 0;

	for (y = 0; y < size; y++)
	{
		diagO += a[(y * size) + y];
		diagT += a[(size - 1) + ((size - 1) * y)];
	}
	printf("%d, %d\n", diagO, diagT);
}
