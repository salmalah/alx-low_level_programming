#include "main.h"
/**
 * *_memset - a function that fills memory with constant bytes
 * @s: memory adress
 * @b: the value
 * @n: number of bytes
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	char buffer[n];
	int i;
	char *x;

	x = &s;
	for (i = 0; i < n; i++)
	{
		buffer[i] = b;
		x = buffer[i];
	}
	return (x);
}

