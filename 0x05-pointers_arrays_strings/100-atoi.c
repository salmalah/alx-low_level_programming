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

	for (i = 0; i < n; i++)
	{
		if (s[0] == '-')
			sign = -1;
		if ( sign > 0)
			num = num * 10 + (s[i] - 48);
		else
			num = (-num * 10 + (s[i] - 48));
	}
	return (num);
}
