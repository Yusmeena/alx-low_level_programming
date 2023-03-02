#include "main.h"
#include <stdio.h>

/**
 * rot13 - encoder rot13
 * @s: pointer to string parameters
 *
 * Return: *s
 */

char *rot13(char *s)
{
	int a;
	int b;
	char lett1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char lettrot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (a = 0; s[a] != '\0'; a++)
	{
		for (b = 0; b < 54; b++)
		{
			if (s[a] == lett1[b])
			{
				s[a] = lettrot[b];
				break;
			}
		}
	}
	return (s);
}
