#include "search_algos.h"
/**
 * binary_search - A function searche value in sorted array using binary search
 * @array: pointer to the first element in array
 * @size: number of elements
 * @value: Value to search
 * Return: -1 if not found or index of the value
 */
int binary_search(int *array, size_t size, int value)
{
	int l, r, i, mid;

	l = 0;
	r = size - 1;
	if (array == NULL)
		return (-1);
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		printf("Searching in array: ");
		for (i = l; i <= r; i++)
		{
			printf("%d", array[i]);
			if (i < r)
				printf(", ");
			else
				printf("\n");
		}
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return (-1);
}
