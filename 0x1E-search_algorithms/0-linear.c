#include "search_algos.h"
/**
 * linear_search - Function searches value in array using
 * linear search algorithm
 * @array: pointer to the first element of array
 * @size: size of element in array
 * @value: value to search
 * Return: -1 If value is not present in array or NULL
 */
int linear_search(int *array, size_t size, int value)
{
	size_t x;


	if (array == NULL)
		return (-1);
	for (x = 0; x < size; x++)
	{
		printf("Value checked array[%lu] = [%d]\n", x, array[x]);
		if (array[x] == value)
			return (x);
	}
	return (-1);
}

