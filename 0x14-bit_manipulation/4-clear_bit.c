#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: input number
 * @index: index
 * Return: 1 if it successful or -1 if an error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int T;

	T = ~(1 << index);
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	*n &= T;
	return (1);
}
