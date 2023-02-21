#include "main.h"
/**
 * times_table - Check description
 * Description: It a function that prints the 9 times table, starting with 0
 * Return: 0 if seccussful else 0
 */
void times_table(void)
{
	int n;
	int i;
	int M;

	n = 0;

	while (n < 10)
	{
		for (i = 1; i <= 10; ++i)
		{
			M = i * n;
			_putchar(M);
		}
		_putchar(',');
		_putchar(' ');
		n++;
	}
}
