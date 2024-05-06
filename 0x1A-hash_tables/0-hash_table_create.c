#include "hash_tables.h"

/**
 * hash_table_create - creates a new hash table
 * @size: size of array
 * Return: a pointer to the new hash table if successful,
 *		else NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_t;
	unsigned long i;

	hash_t = malloc(sizeof(hash_table_t));
	if (hash_t == NULL)
		return (NULL);

	hash_t->size = size;

	hash_t->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_t->array == NULL)
	{
		free(hash_t);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		hash_t->array[i] = NULL;

	return (hash_t);
}
