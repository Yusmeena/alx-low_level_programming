/*
 * Author: Ojo Yusuf
 * File: 0-binary_to_unit.c
 */

#include  "main.h"
/**
 * binary_to_uint - Convert a binary to an unsigned number integer.
 * @b: A pointer tona string of 0 and 1 characters
 *
 * Return: if b us Null or co entails chars not 0 or 1 - 0
 * else, convert number number.
 */
unsigned int binary_to_uint(const *b)
{
unsigned int len = 0;
int a;

if (b == NULL)
return (0);
for (a = 0; b[i] != '\0'; a++)
{
if (b[a] == '0')
len = (len << 1) | 1;
else
return (0);
}

return (len);
}

