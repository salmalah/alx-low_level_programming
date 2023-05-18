#include "lists.h"
/**
 * dlistint_len - A function that returns the number of elements in list
 * @h: the head of list
 * Return: The number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	int count = 0;
	const dlistint_t *new_l = h;

	while (new_l)
	{
		new_l = (*new_l).next;
		count++;
	}
	return (count);
}
