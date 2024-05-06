#include "hash_tables.h"

/**
 * shash_table_create - creates a new hash table
 * @size: size of array
 * Return: a pointer to the new hash table if successful,
 *		else NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *s_ht;
	unsigned long int i;

	s_ht = malloc(sizeof(shash_table_t));
	if (s_ht == NULL)
		return (NULL);
	s_ht->size = size;
	s_ht->shead = NULL;
	s_ht->stail = NULL;

	s_ht->array = malloc(sizeof(shash_node_t *) * size);
	if (s_ht->array == NULL)
	{
		free(s_ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		s_ht->array[i] = NULL;

	return (s_ht);
}

/**
 * create_shash_node - creates a node for the sorted hash table.
 * @key: key for the data
 * @val: value assiciated with the key
 * Return: ptr to the new node, or NULL on failure.
 */
shash_node_t *create_shash_node(const char *key, const char *val)
{
	shash_node_t *s_hash_node;

	s_hash_node = malloc(sizeof(shash_node_t));
	if (s_hash_node == NULL)
		return (NULL);

	/* duplicate and store the key */
	s_hash_node->key = strdup(key);
	if (s_hash_node->key == NULL)
	{
		free(s_hash_node);
		return (NULL);
	}

	/* duplicate and store the value */
	s_hash_node->value = strdup(val);
	if (s_hash_node->value == NULL)
	{
		free(s_hash_node->key);
		free(s_hash_node);
		return (NULL);
	}

	s_hash_node->next = s_hash_node->snext = s_hash_node->sprev = NULL;
	return (s_hash_node);
}

/**
 * insert_node_slist - inserts a node to the linked list
 * @table: the sorted hash table
 * @node: the node to add
 */
void insert_node_slist(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *sht_curr;

	/* If the sorted list is empty, make the node the head and tail */
	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}

	sht_curr = table->shead;
	while (sht_curr != NULL)
	{
		/* Insert the node at the correct position based on key's ASCII order */
		if (strcmp(node->key, sht_curr->key) < 0)
		{
			node->snext = sht_curr;
			node->sprev = sht_curr->sprev;
			sht_curr->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		sht_curr = sht_curr->snext;
	}

	/* If the node has the highest key, make it the new tail */
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - adds an element to the hash table
 * @ht: hash table to add the key/value pair to
 * @key: the key to be hashed, cannot ve an empty string
 * @value: the value associated with the key
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *new_value;
	shash_node_t *s_hash_node, *sht_curr;

	/* Check for invalid input or empty hash table */
	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
		key == NULL || strlen(key) == 0 || value == NULL)
		return (0);

	/* Get the index for the key */
	idx = key_index((const unsigned char *)key, ht->size);
	sht_curr = ht->array[idx];

	/* Update the value if the key already exists */
	while (sht_curr != NULL)
	{
		if (strcmp(sht_curr->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(sht_curr->value);
			sht_curr->value = new_value;
			return (1);
		}
		sht_curr = sht_curr->next;
	}

	/* cerate a new hash node */
	s_hash_node = create_shash_node(key, value);
	if (s_hash_node == NULL)
		return (0);
	s_hash_node->next = ht->array[idx];
	ht->array[idx] = s_hash_node;
	insert_node_slist(ht, s_hash_node);
	return (1);
}

/**
 * shash_table_get - adds an element to the hash table
 * @ht: hash table to add the key/value pair to
 * @key: the key to be hashed, cannot ve an empty string
 * @value: the value associated with the key
 *
 * Return: The value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *s_hash_t_curr;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
		key == NULL || strlen(key) == 0)
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	s_hash_t_curr = ht->array[idx];

	while (s_hash_t_curr != NULL)
	{
		if (strcmp(s_hash_t_curr->key, key) == 0)
			return (s_hash_t_curr->value);
		s_hash_t_curr = s_hash_t_curr->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a hash table
 * @ht: the hash table to be printed
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *s_hash_t_curr;
	char first_char = 0;

	if (ht == NULL || ht->array == NULL)
		return;

	putchar('{');

	s_hash_t_curr = ht->shead;
	while (s_hash_t_curr != NULL)
	{
		if (first_char == 1)
			printf(", ");
		printf("'%s': '%s'", s_hash_t_curr->key, s_hash_t_curr->value);
		first_char = 1;
		s_hash_t_curr = s_hash_t_curr->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order
 * @ht: the hash table to be printed
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *s_hash_t_curr;
	char first_char = 0;

	if (ht == NULL || ht->array == NULL)
		return;

	putchar('{');

	s_hash_t_curr = ht->stail;
	while (s_hash_t_curr != NULL)
	{
		if (first_char == 1)
			printf(", ");
		printf("'%s': '%s'", s_hash_t_curr->key, s_hash_t_curr->value);
		first_char = 1;
		s_hash_t_curr = s_hash_t_curr->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the hash table to be delete.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *next_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	for (i = 0; i < ht->size; ++i)
	{
		while (ht->array[i])
		{
			next_node = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = next_node;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
