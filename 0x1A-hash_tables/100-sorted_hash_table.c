#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - A function create a sorted hash table
 * @size: The size of shash table
 * Retunr: NULL or pointer to the sorted table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *st = malloc(sizeof(shash_table_t));
	unsigned long int in;

	if (st == NULL)
		return (NULL);
	st->size = size;
	st->array = malloc(sizeof(shash_node_t *) * size);
	if (st->array == NULL)
	{
		return (NULL);
	}
	for (in = 0; in < size; in++)
		st->array[in] = NULL;
	st->shead = NULL;
	st->stail = NULL;
	return (st);
}
/**
 * shash_table_set - A function add element to shash table
 * @ht: pointer to the table
 * @key: the key
 * @value: value associated with key
 * Return: 0 or 1
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}

	return (1);
}
/**
 * shash_table_get - a function get value with key from hash table
 * @key: the key
 * Return: the value associated with key or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *n;
	unsigned long int j;

	j = key_index((const unsigned char *)key, ht->size);
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	if (j >= ht->size)
		return (NULL);
	n = ht->shead;
	while (n != NULL && strcmp(n->key, key) != 0)
		n = n->snext;
	return ((n == NULL) ? NULL : n->value);
}
/**
 * shash_table_print - A function print shash table in order
 * @ht: pointer to the shash table
 * Return: nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *no;

	if (ht == NULL)
		return;
	no = ht->shead;
	printf("{");
	while (no != NULL)
	{
		printf("'%s': '%s'", no->key, no->value);
		no = no->snext;
		if (no != NULL)
			printf(", ");
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - A Function prints shash table in reverse
 * @ht: ointer to the table
 * Return: nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *n;

	if (ht == NULL)
		return;
	n = ht->stail;
	printf("{");
	while (n != NULL)
	{
		printf("'%s': '%s'", n->key, n->value);
		n = n->sprev;
		if (n != NULL)
			printf(", ");
	}
	printf("}\n");
}
/**
 * shash_table_delete - A function delete a sorted shash table
 * @ht: pointer to the table
 * Return: nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *nod, *tp;
	shash_table_t *h = ht;

	if (ht == NULL)
		return;
	nod = ht->shead;
	while (nod)
	{
		tp = nod->snext;
		free(nod->key);
		free(nod->value);
		free(nod);
		nod = tp;
	}
	free(h->array);
	free(h);
}
