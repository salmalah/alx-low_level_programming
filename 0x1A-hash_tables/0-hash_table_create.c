#include "hash_tables.h"

/**
 * hash_table_create - A function that creates a hash table
 * @size: size of array
 * Return: pointer to the newly created hash table else NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int index;
	hash_table_t *h;

	h = malloc(sizeof(hash_table_t));
	if (!h)
		return (NULL);
	h->size = size;
	h->array = malloc(sizeof(hash_node_t *) * size);
	if (!h->array)
		return (NULL);
	for (index = 0; index < size; index++)
		h->array[index] = NULL;
	return (h);

}
