#include "lists.h"

/**
 * delete_dnodeint_at_index - A a function that deletes the node at index
 * @head: A pointer to the head
 * @index: index of the node to delete.
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur = *head;

	if (!*head)
		return (-1);

	while (index != 0)
	{
		if (!cur)
			return (-1);
		cur = cur->next;
		index--;
	}
	if (cur == *head)
	{
		*head = cur->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		cur->prev->next = cur->next;
		if (cur->next != NULL)
			cur->next->prev = cur->prev;
	}
	free(cur);
	return (1);
}
