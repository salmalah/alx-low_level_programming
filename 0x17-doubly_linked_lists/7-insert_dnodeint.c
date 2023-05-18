#include "lists.h"
/**
 * *insert_dnodeint_at_index - A function that inserts a
 * new node at a given position
 * @h: A head pointer
 * @idx: position to insert the new node
 * @n: value of new node
 * Return: NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *cur = *h, *new_n;

	new_n = malloc(sizeof(dlistint_t));
	if (new_n == NULL)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	if ((*cur).next == NULL)
		return (add_dnodeint_end(h, n));
	for (; idx != 1; idx--)
	{
		cur = cur->next;
		if (cur == NULL)
			return (NULL);
	}
	new_n->n = n;
	new_n->prev = cur;
	new_n->next = cur->next;
	cur->next->prev = new_n;
	cur->next = new_n;

	return (new_n);
}
