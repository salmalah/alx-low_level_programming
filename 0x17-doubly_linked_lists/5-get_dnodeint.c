#include "lists.h"
/**
 * *get_dnodeint_at_index - A function that returns the nth node of list
 * @head: the head of list
 * @index: the index of the node
 * Return: Null if node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
        unsigned int count = 0;
        dlistint_t *new_l = head;

        while (new_l)
        {
		if (count == index)
			return new_l;
                new_l = (*new_l).next;
                count++;
        }
        return (NULL);
}
