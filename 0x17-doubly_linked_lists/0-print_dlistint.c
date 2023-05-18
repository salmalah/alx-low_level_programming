#include "lists.h"

/*
 * print_dlistint - Check description
 * Description: is a function Prints all the elements of a dlistint_t list.
 * @h: the head of dlistint_t list
 * Return: the number of nodes in list
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *new_l = h;
	int count = 0;

	while (new_l)
	{
		printf("%d\n", (*new_l).n);
		new_l = (*new_l).next;
		count++;
	}
	return (count);
}
