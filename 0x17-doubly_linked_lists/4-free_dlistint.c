#include "lists.h"
/**
 * free_dlistint - A function that frees a dlistint_t list.
 * @head: A pointer to head
 * Return: Nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *l = head;
	dlistint_t *ptr;

	if (l)
	{
		ptr = l->next;
		free(l);
		l = ptr;
	}
}
