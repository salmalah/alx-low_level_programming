#include "main.h"
/**
 * times_table - Check description
 * Description: It a function that prints the 9 times table, starting with 0
 * Return: 0 if seccussful else 0
 */
void times_table(void)
{
	int n, i, j;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			n = i * j;
			_putchar(n + '0');
			_putchar(',');
			_putchar(' ');
		}
		_putchar('\n');
	}
}
