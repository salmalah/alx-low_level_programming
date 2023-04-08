#include "main.h"
#include <string.h>
/**
 * binary_to_uint - a function that converts a
 * binary number to an unsigned int
 * @b: binary number
 * Return: usigned integer
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int k = 1, f = 0, length;
	int l;

	length = strlen(b);
	for (l = length - 1; l >= 0; l--)
	{
		if (b[l] != '0' && b[l] != '1')
			return (0);
		if (b[l] == '1')
			f += k;
		k *= 2;
	}
	return (f);
}
