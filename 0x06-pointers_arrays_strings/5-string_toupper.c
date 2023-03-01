#include "main.h"
#include <string.h>
/**
 * string_toupper - a function that changes all lowercase letters of a  string
 * @s: an input string
 * Return: char pointer to converted string
 */
char *string_toupper(char *s)
{
	int len;

	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s >= 'a' && s <= 'z')
			s -= 32;
	}
	return (s);
}
