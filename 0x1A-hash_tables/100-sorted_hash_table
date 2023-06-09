#include "hash_tables.h"
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
	n = ht->shead;
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	if (j >= ht->size)
		return (NULL);
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
	shash_table_t *st = malloc(sizeof(shash_table_t));
	unsigned long int index;

	if (st == NULL)
		return (NULL);
	st->size = size;
	st->array = malloc(sizeof(shash_node_t *) * size);
	st->shead = NULL;
	st->stail = NULL;
	if (st->array == NULL)
	{
		free(st);
		return (NULL);
	}
	for (index = 0; index < size; index++)
		st->array[index] = NULL;
	return (st);
}
/**
 * shash_table_print - A function print shash table in order
 * @ht: pointer to the shash table
 * Return: nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	int fr = 1;
	shash_node_t *no;

	if (ht == NULL)
		return;
	printf("{");
	no = ht->shead;
	while (no != NULL)
	{
		if (!fr)
			printf(", ");
		printf("'%s': '%s'", no->key, no->value);
		fr = 0;
		no = no->snext;
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
	unsigned long int in;

	for (in = 0; in < ht->size; in++)
	{
		nod = ht->array[in];
		while (nod != NULL)
		{
			tp = nod->next;
			free(nod->key);
			free(nod->value);
			free(nod);
			nod = tp;
		}
	}
	free(ht->array);
	free(ht);
}
/**
 * shash_table_print_rev - A Function prints shash table in reverse
 * @ht: ointer to the table
 * Return: nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	int ft = 1;
	shash_node_t *n;

	if (ht == NULL)
		return;
	printf("{");
	n = ht->stail;
	while (n != NULL)
	{
		if (!ft)
			printf(", ");
		printf("'%s': '%s'", n->key, n->value);
		ft = 0;
		n = n->sprev;
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
	unsigned long int i;
	shash_node_t *n, *prv, *new_n;

	i = key_index((const unsigned char *)key, ht->size);
	n = ht->array[i];
	new_n = malloc(sizeof(shash_node_t));
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	if (new_n == NULL)
		return (0);
	while (n != NULL)
	{
		if (strcmp(n->key, key) == 0)
		{
			free(n->value);
			n->value = strdup(value);
			return (1);
		}
		n = n->next;
	}
	new_n->key = strdup(key);
	new_n->value = strdup(value);
	new_n->next = ht->array[i];
	new_n->sprev = NULL;
	new_n->snext = NULL;
	ht->array[i] = new_n;
	if (ht->shead == NULL)
	{
		ht->shead = new_n;
		ht->stail = new_n;
	}
	else
	{
		prv = NULL;
		n = ht->shead;
		while (n != NULL && strcmp(key, n->key) > 0)
		{
			prv = n;
			n = n->snext;
		}
		if (prv == NULL)
		{
			new_n->snext = ht->shead;
			ht->shead->sprev = new_n;
			ht->shead = new_n;
		}
		else if (n == NULL)
		{
			new_n->sprev = ht->stail;
			ht->stail->snext = new_n;
			ht->stail = new_n;
		}
		else
		{
			prv->snext = new_n;
			new_n->sprev = prv;
			new_n->snext = n;
			n->sprev = new_n;
		}
	}
	return (1);
}
