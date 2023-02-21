#include "main.h"
/**
 * print_to_98 - Check description
 * Description: It a function that prints all natural numbers from n to 98
 * Return : 0 if seccussful else 1
 */
void print_to_98(int n)
{
	int i;

	for(i = n ; i <= 98; i++)
	{
		_putchar(i);
		_putchar(',');
		_putchar(' ');
	}
}
