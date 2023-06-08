#include "hash_tables.h"

/**
 * hash_table_delete - A funtion delete a hash table
 * @ht: A pointer to the hash table
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int u;
	hash_node_t *n, *t;

	if (ht == NULL)
		return (NULL);
	for (u = 0; u < ht->size; u++)
	{
		n = ht->array[u];
		while (n != NULL)
		{
			t = n->next;
			free(n->key);
			free(n->value);
			free(n);
			n = t;
		}
	}
	free(ht->array);
	free(ht);
}
