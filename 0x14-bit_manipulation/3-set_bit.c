#include "main.h"

/**
 * set_bit - A function that sets a bit at given index to 1
 * @n: The number
 * @index: The index to set bit at
 * Return: 1 if it worked, or -1 on error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int T;

	T = 1 << index;
	if (T == 0)
		return (-1);
	*n |= T;
	return (1);
}
