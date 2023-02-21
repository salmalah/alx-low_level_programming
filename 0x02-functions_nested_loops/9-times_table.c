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
		_putchar(48);
		for (j = 0; j <= 9; j++)
		{
			n = i * j;
			_putchar(',');
			_putchar(' ');
			if (n <= 9)
				_putchar(' ');
			else
				_putchar((n / 10) + 48);
			putchar((n % 10) + 48);
		}
		_putchar('\n');
	}
}
