#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * new_dog - creates new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: a dog object
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int j, len1, len2;
	dog_t *ndog;
	char *c, *d;

	len1 = 0;
	for (j = 0; name[j] != '\0'; j++)
		len1++;
	len2 = 0;
	for (j = 0; owner[j] != '\0'; j++)
		len2++;
	ndog = malloc(sizeof(dog_t));
	if (ndog == NULL)
		return (NULL);
	c = malloc((len1 + 1) * sizeof(char));
	if (c == NULL)
	{
		free(ndog);
		return (NULL);
	}
	for (j = 0; j < len1; j++)
		c[j] = name[j];
	c[j] = '\0';
	ndog->name = c;
	ndog->age = age;
	d = malloc((len2 + 1) * sizeof(char));
	if (d == NULL)
	{
		free(c);
		free(ndog);
		return (NULL);
	}
	for (j = 0; j < len2; j++)
		d[j] = owner[j];
	d[j] = '\0';
	ndog->owner = d;
	return (ndog);
}
