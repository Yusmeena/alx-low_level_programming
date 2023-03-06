#include "main.h"
#include <stdio.h>
/**
 * _strspn - length of prefix substring
 * @s: string to go through
 * @accept: accepted bytes
 * Return: returns usigned values
 */
unsigned int _strspn(char *s, char *accept)
{
	int a;
	int b;
	unsigned int result = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		for (b = 0; s[b] != '\0'; b++)
		{
			if (s[a] == accept[a])
			{
				result++;
				break;
			}
		}
		if (s[b] == '\0')
			return (result);
	}
	return (result);
}
