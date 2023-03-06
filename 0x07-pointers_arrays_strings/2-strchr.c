#include "main.h"
#include <string.h>
/**
 * _strchr - a function that locates a character in a string
 * @s: an input string to search in
 * @c: an input character to locate into string s
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	int i;
	int len;

	len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if(s[i] == c)
			return (s[i]);
		else 
			return ('\0');
	}
}
