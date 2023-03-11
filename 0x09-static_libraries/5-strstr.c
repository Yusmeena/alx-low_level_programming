#include "main.h"
/**
 * _strstr - locates substring
 * @haystack: string to locate
 * @needle: substring to locate
 * Return: returns string at starting sub or null
 */
char *_strstr(char *haystack, char *needle)
{
	int a;
	int b;

	if (needle[0] == '\0')
		return (haystack);

	for (a = 0; haystack[a] != '\0'; a++)
	{
		if (haystack[a] == needle[0])
		{
			for (b = 0; needle[b] != '\0'; b++)
			{
				if (haystack[a + b] != needle[b])
					break;
			}
			if (needle[b] == '\0')
				return (haystack + a);
		}

	}
	return ('\0');
}
