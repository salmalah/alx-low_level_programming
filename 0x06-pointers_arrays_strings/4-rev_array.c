#include "main.h"
/**
 * reverse_array - function that reverses the content of an array of integers
 * @a: array
 * @n: number of elements of the array
 */
void reverse_array(int *a, int n)
{
	int i;
	int j = 0;
	int rev[n];

	for (i = n -1 ; i >= 0; i--)
	{
		rev[j] = a[i];
		j++;
	}
	for (i = 0; i < n; i++)
	{
		a[i] = rev[i];
	}
		
}
