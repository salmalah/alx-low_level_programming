#include "main.h"

/**
 * get_bit - returns the value of a bit at a given
 * @n: input number.
 * @index: index of the bit.
 * Return: value of the bit.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int var;

	if (n == 0 && index < 64)
		return (0);

	for (var = 0; var <= 63; n >>= 1, var++)
	{
		if (index == var)
		{
			return (n & 1);
		}
	}

	return (-1);
}
