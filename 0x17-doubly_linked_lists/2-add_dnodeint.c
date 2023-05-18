#include "lists.h"
/**
 * *add_dnodeint - A function that adds a new node at the beginning of a list
 * @head: A pointer to the head list
 * @n: In integer
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *ptr;

	ptr = malloc(sizeof(dlistint_t));
	if (!ptr)
		return (NULL);
	if (*head)
		(*head)->prev = ptr;
	ptr->n = n;
	ptr->prev = NULL;
	ptr->next = *head;
	*head = ptr;
	return (ptr);
}
