#include "variadic_functions.h"
#include <stdarg.h>
/**
 * sum_them_all - A function that sums all its parameters.
 * @n: number of parameters
 * @...: Other parameters
 * Return: The of all parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list list;

	if (n == 0)
		return (0);
	va_start(list, n);
	unsigned int i;
	int sum = 0;

	for (i = 0; i < n; i++)
	{
		sum = sum + va_arg(list, int);
	}
	va_end(list);
	return (sum);
}
