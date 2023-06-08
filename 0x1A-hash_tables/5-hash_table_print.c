#include "hash_tables.h"

/**
 * hash_table_print - a function that prints a hash table
 * @ht: is the hash table
 * Return: nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *n;
	unsigned long int j;
	int num = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (j = 0; j < ht->size; j++)
	{
		n = ht->array[j];
		while (n != NULL)
		{
			if (num)
				num = 0;
			else
				printf(", ");
			printf("'%s': '%s'", n->key, n->value);
			n = n->next;
		}
	}
	printf("}\n");
}
