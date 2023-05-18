#include "lists.h"
/**
 * sum_dlistint - A function that print sum of list elements
 * @head: The pointer to head of the list
 * Return: the sum
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *new_l = head;

	while (new_l)
	{
		sum += new_l->n;
		new_l = (*new_l).next;
	}
	return (sum);
}
