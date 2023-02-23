#include "main.h"
/**
 * _isdigit - Check description
 * description: It a function that checks for a digit
 * @c: Input number
 * Return: 0 if seccussful else 1
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		_putchar(c);
		_putchar(':');
		_putchar(' ');
		return (1);
	}
	else
	{
		_putchar(c);
		_putchar(':');
		_putchar(' ');
		return (0);
	}
	_putchar('\n');
	return (0);
}
