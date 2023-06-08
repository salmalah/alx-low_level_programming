#include "hash_tables.h"

/**
 * key_index - a function that gives you the index of a key
 * @key: key
 * @size: is the size of the array of the hash table
 * Return: index for the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_v;

	hash_val = hash_djb2(key);
	return (hash_val % size);
}
