#include "main.h"
/**
 * _strchr - locates character in a string
 * @s: string to locate char
 * @c: character to find
 * Return: character value
 */
char *_strchr(char *s, char c)
{
	int a;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] == c)
		{
			return (s + a);
		}
	}
	if (s[a] == c)
		return (s + a);
	return (0);
}
