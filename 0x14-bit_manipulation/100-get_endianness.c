#include "main.h"

/**
 * get_endianness - Checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int x = 0x01;
	char *b_ptr = (char *)&x;

	if (*b_ptr == 1)
	{
		return (1);
	}
	else
		return (0);
}
