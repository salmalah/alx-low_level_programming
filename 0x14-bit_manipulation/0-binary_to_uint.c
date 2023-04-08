#include "main.h"
/**
 * binary_to_uint - a function that converts a binary number to an unsigned int
 *
 * @b: binary number
 * Return: usigned integer 
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	if (b == NULL)
		return (0);
	for (int f = 0; b[f] != '\0'; f++)
	{
		 if (b[f] == '0')
			 num = num << 1;
		 else if (b[f] == '1')
			 num = (num << 1) | 1;
		 else
			 return (0);
	}
	return (num);
}
