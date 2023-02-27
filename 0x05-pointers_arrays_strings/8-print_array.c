#include "main.h"
#include <string.h>
/**
 * print_array - a function that prints n elements of an array of integers
 * @a: an input array
 * @n: an input integer
 */
void print_array(int *a, int n)
{
	int len;
	int i;

	for (i = 0; i < n ; i++)
	{
		printf("%d, ",a[i]);
	}
}
