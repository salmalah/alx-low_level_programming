#include "main.h"
/**
 * print_to_98 - Check description
 * @n: input number
 * Description: It a function that prints all natural numbers from n to 98
 * Return : 0 if seccussful else 1
 */
void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		_putchar(n + '0');
		_putchar(',');
		_putchar(' ');
		n++;
	}
	else if (n >= 98)
	{
		_putchar(n + '0');
		_putchar(',');
		_putchar(' ');
		n--;
	}
}
