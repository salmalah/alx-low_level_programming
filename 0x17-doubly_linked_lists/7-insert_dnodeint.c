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
	dlistint_t *new_n, *curt;
	unsigned int coun = 0;

	curt = *h;
	new_n = malloc(sizeof(dlistint_t));
	new_n->n = n;
	if (curt == NULL || new_n == NULL)
		return (NULL);
	if (idx == 0)
		return (new_n = add_dnodeint(h, n));
	if (curt->next == NULL)
		return (add_dnodeint_end(h, n));
	while (curt != NULL && coun < idx - 1)
	{
		curt = curt->next;
		coun++;
	}
	new_n->next = curt->next;
	new_n->prev = curt;
	if (curt->next != NULL)
		curt->next->prev = new_n;
	curt->next = new_n;
	return (new_n);
}
