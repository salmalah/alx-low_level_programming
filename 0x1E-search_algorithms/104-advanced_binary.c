#include "search_algos.h"
/**
  * advanced_binary_r  - A Function searches recursively for
  * a value in a sorted array
  * @array: A pointer to the first element of the [sub]array
  * @l: start index of the [sub]array
  * @r: end index of the [sub]array to search.
  * @value: The value to search
  * Return: If the value is not present, or -1.
  */
int advanced_binary_r(int *array, size_t l, size_t r, int value)
{
	size_t x;

	if (r < l)
		return (-1);
	printf("Searching in array: ");
	for (x = l; x < r; x++)
		printf("%d, ", array[x]);
	printf("%d\n", array[x]);
	x = l + (r - l) / 2;
	if (array[x] == value && (x == l || array[x - 1] != value))
		return (x);
	if (array[x] >= value)
		return (advanced_binary_r(array, l, x, value));
	return (advanced_binary_r(array, x + 1, r, value));
}
/**
  * advanced_binary - A Function Searches for a value in a sorted array
  * @array: A pointer to the first element of the array
  * @size: number of elements in the array
  * @value: value to search for
  * Return: If the value is not present or the array is NULL,or  -1
  */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_binary_r(array, 0, size - 1, value));
}
