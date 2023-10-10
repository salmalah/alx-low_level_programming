#include "search_algos.h"
#include <stdio.h>

/**
 * interpolation_search - A function searches for a value in a sorted
 * array using interpolation search
 * @array: pointer to the first element of array
 * @size: number of elements
 * @value: value to search
 * Return: -1 or index of the value in the array
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos;
	int l, h;

	if (array == NULL || size == 0)
		return (-1);
	l = 0;
	h = size - 1;
	while (l <= h && value <= array[h] && value >= array[l])
	{
		pos = l + (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			l = pos + 1;
		else
			h = pos - 1;
	}
	printf("Value checked array[%d] is out of range\n", h);
	return (-1);
}
