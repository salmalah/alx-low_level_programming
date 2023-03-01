#include "main.h"
#include <string.h>
/**
 * *_strcat - a function that concatenates two strings
 * @dest: an input string
 * @src: an input string
 * Return: A pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *copy = dest;
	int i;
	int len;

	len = strlen(src);
	for (i = 0; i < len; i++)
	{
		dest = src[i];
	}
	copy += dest;
	return (copy);
}
