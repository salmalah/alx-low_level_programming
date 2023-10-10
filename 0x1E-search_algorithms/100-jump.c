#include "search_algos.h"
/**
 * jump_search - A function sarches a value in a sorted array using jump search
 * @array: pointer to the first element of array
 * @size: number of elements
 * @value: value to search
 * Return: -1 if not found or index of the value in the array
 */
int jump_search(int *array, size_t size, int value)
{
	int jump_s, l, x, r;

	jump_s = sqrt(size);
	l = 0;
	r = 0;
	if (array == NULL || size == 0)
		return (-1);
	while (r < (int)size && array[r] < value)
	{
		printf("Value checked array[%d] = [%d]\n", r, array[r]);
		l = r;
		r += jump_s;
	}
	printf("Value found between indexes [%d] and [%d]\n", l, r);
	r = (r < (int)size) ? r : (int)(size - 1);
	for (x = l; x <= r; x++)
	{
		printf("Value checked array[%d] = [%d]\n", x, array[x]);
		if (array[x] == value)
			return (x);
	}
	return (-1);
}
