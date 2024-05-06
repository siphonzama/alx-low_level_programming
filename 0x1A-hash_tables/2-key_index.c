#include "hash_tables.h"

/**
 * key_index - Computes the index at which a key should be placed
 *			   on the hash table array
 * @key: the key to be hashed
 * @size: size of the hash table array
 *
 * Return: the index of the key/value pair stored on the hash table array.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash, index;

	hash = hash_djb2(key);
	index = hash % size;

	return (index);
}
