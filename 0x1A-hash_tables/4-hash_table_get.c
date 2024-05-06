#include "hash_tables.h"

/**
 * hash_table_get - finds the value associated with a key from the hash table
 * @ht: hash table to look in to
 * @key: key being looked for
 *
 * Return: the value associated with the element, or NULL if key not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *hash_t_container;
	unsigned long int idx;

	if (!ht || !key || !(*key))
		return (NULL);

	idx = key_index((unsigned char *)key, ht->size);
	hash_t_container = ht->array[idx];

	while (hash_t_container)
	{
		if (strcmp(hash_t_container->key, key) == 0)
			return (hash_t_container->value);
		hash_t_container = hash_t_container->next;
	}
	return (NULL);
}
