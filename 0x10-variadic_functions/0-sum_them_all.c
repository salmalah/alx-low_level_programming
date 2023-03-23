#include "variadic_functions.h"
#include <stdarg.h>
/**
 * sum_them_all - A function that sums all its parameters.
 * @n: number of parameters
 * @...: Other parameters
 * Return: If n == 0 - 0.
 * Otherwise - the sum of all parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
        va_list list;
        unsigned int i, sum = 0;

        if (n == 0)
                return (0);
	else
	{
		va_start(list, n);
		for (i = 0; i < n; i++)
			sum += va_arg(list, int);
		va_end(list);
		return (sum);
	}
}
