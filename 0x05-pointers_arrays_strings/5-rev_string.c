#include <string.h>
#include "main.h"
/**
 * rev_string - a function that reverse a string
 * @s: an input string
 * Return: Nothing
 */
void rev_string(char *s)
{
	int len;
	int rev;
	int i;

	len = strlen(s);
	i = 0;
	while (i < len--)
	{
		rev = s[i];
		s[i++] = s[len];
		s[len] = rev;
	}
}
