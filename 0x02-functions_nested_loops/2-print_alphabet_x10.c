#include "main.h"
/**
 * print_alphabet_x10 - Ceck description
 * Description: It prints 10 times the alphabet in lowercase
 * Return: 0 if successful else 1
 */
void print_alphabet_x10(void)
{
	char c;
	int n;

	while (n < 10)
	{
		for (c = 'a'; c <= 'z'; c++)
		{
			_putchar(c);
		}
		_putchar('\n');
		n++;
	}
}
