#include "search_algos.h"
/**
 * jump_list - Function searches for an algorithm in
 * a sorted singly linked list
 * @list: pointer to the  head of the linked list to search
 * @size: number of nodes in the list
 * @value: value to search for
 * Return: NULL or value is not present or the head of the list is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *n, *j;
	size_t s, step_s;

	if (!list || size == 0)
		return (NULL);
	step_s = sqrt(size);
	s = 0;
	for (n = j = list; j->index + 1 < size && j->n < value;)
	{
		n = j;
		for (s += step_s; j->index < s; j = j->next)
		{
			if (j->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", j->index, j->n);
	}
	printf("Value found between indexes [%ld] and [%ld]\n", n->index, j->index);
	for (; n->index < j->index && n->n < value; n = n->next)
		printf("Value checked at index [%ld] = [%d]\n", n->index, n->n);
	printf("Value checked at index [%ld] = [%d]\n", n->index, n->n);
	return (n->n == value ? n : NULL);
}
