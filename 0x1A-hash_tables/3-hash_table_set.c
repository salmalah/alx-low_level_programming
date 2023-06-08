#include "hash_tables.h"

/**
 * hash_table_set - a Function add/update an element in a hash table
 * @ht: A pointer to the hash table
 * @key: The key
 * @value: The value associated with key.
 * Return: 0 if secessful else 1
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_n;
	char *key_copy;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	key_copy = strdup(value);
	if (key_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = key_copy;
			return (1);
		}
	}

	new_n = malloc(sizeof(hash_node_t));
	if (new_n == NULL)
	{
		free(key_copy);
		return (0);
	}
	new_n->key = strdup(key);
	if (new_n->key == NULL)
	{
		free(new_n);
		return (0);
	}
	new_n->value = key_copy;
	new_n->next = ht->array[index];
	ht->array[index] = new_n;

	return (1);
}
