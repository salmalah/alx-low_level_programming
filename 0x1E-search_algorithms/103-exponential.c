#include "search_algos.h"
/**
  * binary_s - A Function searche for a value in a sorted array
  * @array: A pointer to the first element of the array
  * @l: The starting index of the [sub]array to search.
  * @r: The ending index of the [sub]array to search.
  * @value: The value to search for
  * Return: the value is not present or the array is NULL -1
  */
int binary_s(int *array, size_t l, size_t r, int value)
{
	size_t y;

	if (array == NULL)
		return (-1);
	while (r >= l)
	{
		printf("Searching in array: ");
		for (y = l; y < r; y++)
			printf("%d, ", array[y]);
		printf("%d\n", array[y]);
		y = l + (r - l) / 2;
		if (array[y] == value)
			return (y);
		if (array[y] > value)
			r = y - 1;
		else
			l = y + 1;
	}
	return (-1);
}

/**
  * exponential_search - A Function searches for a value in a sorted array
  * of integers using exponential
  * @array: A pointer to the first element
  * @size: The number of elements in the array
  * @value: The value to search
  * Return: Index of the value in the array, or -1 if not found
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t x = 0, r;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (x = 1; x < size && array[x] <= value; x = x * 2)
			printf("Value checked array[%ld] = [%d]\n", x, array[x]);
	}
	r = x < size ? x : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", x / 2, r);
	return (binary_s(array, x / 2, r, value));
}
