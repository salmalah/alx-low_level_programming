#include "main.h"
#include <string.h>
/**
 * _atoi - a function that converts string to integer
 * @s: An input string
 * Return: integer from conversion
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int n = strlen(s);
	int i;

	for (i = 0; i < n; i++)
	{
		num = num * 10 + (s[i] - 48);
	}
	return (num);
}
