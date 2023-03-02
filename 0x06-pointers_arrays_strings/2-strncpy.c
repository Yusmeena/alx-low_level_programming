#include "main.h"
/**
 * _strncpy - copy a string
 * @dest: input value1
 * @src: input value2
 * @n: input value
 *
 * Return: destination
 */
char *_strncpy(char *dest, char *src, int n)
{
	int b;

	b = 0;
	while (b < n && src[b] != '\0')
	{
		dest[b] = src[b];
		b++;
	}
	while (b < n)
	{
		dest[b] = '\0';
		j++;
	}

	return (dest);
}
