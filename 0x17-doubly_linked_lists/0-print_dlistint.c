#include "lists.h"
/*
 * print_dlistint - A function that prints all the elements of a list
 * @h: the head of list
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *new_l = h;
	int count = 0;

	while (new_l)
	{
		printf("%d\n", new_l->n);
		new_l = new_l->next;
		count++;
	}
	return (count);
}
