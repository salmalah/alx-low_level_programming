#include "main.h"
/**
 * _puts_recursion - a function that prints a string,
 * @s: An input string to printing
 * Return: Nothing
 */
void _puts_recursion(char *s)
{
	int i = char *s;

	if (*s[i])
	{
		_putchar(*s[i]);
		i++;
	}
	else
		_putchar('\n');
}
