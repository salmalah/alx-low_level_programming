#include "main.h"

/**
 * get_bit - A function that gets a bit at index
 * @n: unsigned long int input
 * @index: The index of bit
 * Return: The value of the bit or -1 if an error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int up = 1;

	up <<= index;
	if ((n & up))
		return (1);
	else
		return (0);
	if (!up)
		return (-1);
}
