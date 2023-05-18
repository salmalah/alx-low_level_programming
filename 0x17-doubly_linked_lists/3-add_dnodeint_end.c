#include "lists.h"
/**
 * *add_dnodeint_end - A function that adds a new node at the end  of a list
 * @head: A pointer to the head list
 * @n: In integer
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
        dlistint_t *ptr, *tmp = *head;

        ptr = malloc(sizeof(dlistint_t));
        if (!ptr)
                return (NULL);
	ptr->n = n;
	if (*head == NULL)
	{
		(*ptr).prev = NULL;
		(*ptr).next = NULL;
		*head = ptr;
	}
	else
	{
		while ((*tmp).next != NULL)
			tmp = tmp->next;
		tmp->next = ptr;
		ptr->prev = tmp;
	}
        return (ptr);
}
