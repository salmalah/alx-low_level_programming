#include "search_algos.h"
/**
 * linear_skip - A Function searches for an algorithm in a sorted singly
 * @list: is pointer to the  head of the linked list to search
 * @value: The value to search for
 * Return: NULL or the value is not present or the head of the list is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *n, *jum;

	if (!list)
		return (NULL);
	for (n = jum = list; jum->next != NULL && jum->n < value;)
	{
		n = jum;
		if (jum->expres)
		{
			jum = jum->express;
			printf("Value checked at index [%ld] = [%d]\n",
					jum->index, jum->n);
		}
		else
		{
			while (jum->next)
				jum = jum->next;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			n->index, jum->index);
	for (; n->index < jum->index && n->n < value; n = n->next)
		printf("Value checked at index [%ld] = [%d]\n", n->index, n->n);
	printf("Value checked at index [%ld] = [%d]\n", n->index, n->n);
	return (n->n == value ? n : NULL);
}
