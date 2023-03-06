#include "main.h"
#include <string.h>
/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: first string.
 * @accept: second string.
 * Return: a pointer to the byte in s that matches one of the
 * bytes in accept, or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;
	int len, len2;

	len = strlen(s);
	len2 = strlen(accept);
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len2; j++)
		{
			if (s[i] == accept[j])
				return ([i]);
		}
	}
	return ('\0');
}
