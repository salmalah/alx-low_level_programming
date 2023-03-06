#include "main.h"
#include <string.h>
/**
 * _strchr - a function that locates a character in a string
 * @s: an input string to search in
 * @c: an input character to locate into string s
 * Return: returns pointer to c position
 */
char *_strchr(char *s, char c)
{
	int len;
	int i;

	len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if (s[i] == c)
			return (s[i]);
		else
			return (NULL);
	}
}
