#include "main.h"

/**
 * flip_bits - function that returns the number of bits
 * @n: input number
 * @m: second input number
 * Return: number of
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int dor = n ^ m, check_number = 1;
	unsigned int count = 0, i;

	for (i = 0; i < (sizeof(unsigned long int) * 8); i++)
	{
		if (check_number == (dor & check_number))
			count++;
		check_number <<= 1;
	}
	return (count);
}
