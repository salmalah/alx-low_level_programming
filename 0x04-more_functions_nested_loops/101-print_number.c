#include "main.h"
/**
 * print_number - Check description
 * Description: It a function that prints an integer
 * @n: input integer
 * Return: 0 Always
 */
void print_number(int n)
{
	if (n == 0)
		_putchar('0');
	else if (n < 0)
	{
		_putchar('-');
		_putchar(n + '0');
	}
	else
		_putchar(n + '0');
}
