#include "hash_tables.h"
char *shash_table_get(const shash_table_t *ht, const char *key);
shash_table_t *shash_table_create(unsigned long int size);
void shash_table_print(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
/**
 * shash_table_get - a function get value with key from hash table
 * @key: the key
 * Return: the value associated with key or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *n;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);
	n = ht->shead;
	while (n != NULL && strcmp(n->key, key) != 0)
		n = n->snext;
	return ((n == NULL) ? NULL : n->value);
}
/**
 * shash_table_create - A function create a sorted hash table
 * @size: The size of shash table
 * Retunr: NULL or pointer to the sorted table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *st;
	unsigned long int in;

	st = malloc(sizeof(shash_table_t));
	if (st == NULL)
		return (NULL);
	st->size = size;
	st->array = malloc(sizeof(shash_node_t *) * size);
	if (st->array == NULL)
		return (NULL);
	for (in = 0; in < size; in++)
		st->array[in] = NULL;
	st->shead = NULL;
	st->stail = NULL;
	return (st);
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
 * shash_table_set - A function add element to shash table
 * @ht: pointer to the table
 * @key: the key
 * @value: value associated with key
 * Return: 0 or 1
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_n, *tm;
	char *value_c;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_c = strdup(value);
	if (value_c == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tm = ht->shead;
	while (tm)
	{
		if (strcmp(tm->key, key) == 0)
		{
			free(tm->value);
			tm->value = value_c;
			return (1);
		}
		tm = tm->snext;
	}

	new_n = malloc(sizeof(shash_node_t));
	if (new_n == NULL)
	{
		free(value_c);
		return (0);
	}
	new_n->key = strdup(key);
	if (new_n->key == NULL)
	{
		free(value_c);
		free(new_n);
		return (0);
	}
	new_n->value = value_c;
	new_n->next = ht->array[index];
	ht->array[index] = new_n;

	if (ht->shead == NULL)
	{
		new_n->sprev = NULL;
		new_n->snext = NULL;
		ht->shead = new_n;
		ht->stail = new_n;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_n->sprev = NULL;
		new_n->snext = ht->shead;
		ht->shead->sprev = new_n;
		ht->shead = new_n;
	}
	else
	{
		tm = ht->shead;
		while (tm->snext != NULL && strcmp(tm->snext->key, key) < 0)
			tm = tm->snext;
		new_n->sprev = tm;
		new_n->snext = tm->snext;
		if (tm->snext == NULL)
			ht->stail = new_n;
		else
			tm->snext->sprev = new_n;
		tm->snext = new_n;
	}

	return (1);
}
