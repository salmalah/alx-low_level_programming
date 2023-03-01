#include "main.h"
#include <string.h>
/**
 * _strcmp - a function that compares two strings.
 * @s1: an input string
 * @s2: an input string
 * Return: The difference s1 - s2
 */
int _strcmp(char *s1, char *s2)
{
	int result;

	if (strlen(s1) == strlen(s2))
		result = 0;
	else if (strlen(s1) > strlen(s2))
		result = 15;
	else
		result = (-15);
	return (result);
}
