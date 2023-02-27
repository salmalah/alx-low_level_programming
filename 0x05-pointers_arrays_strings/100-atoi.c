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
	int i = 0;
	int sign = 1;
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (i = 0; i < n; i++)
	{
		num = num * 10 + (s[i] - 48);
	}
	return (num * sign);
}
