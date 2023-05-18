#include "lists.h"
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
