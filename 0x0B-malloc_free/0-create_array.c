#include "main.h"
#include <stdlib.h>
/**
 * create_array - A function that creates an array of chars
 * @size: The size of the array
 * @c: A character to initialized the array
 * Return: Apointer to the array or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	int i = 0;

	if (size == 0)
		return (NULL);
	c = malloc(n * sizeof(char));
	if (c == 0)
		return (NULL);
	while (i < size - 1)
	{
		c[i] = c;
		i++;
	}
	return (c);
}

