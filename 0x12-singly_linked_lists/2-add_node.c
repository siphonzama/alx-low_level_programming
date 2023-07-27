#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node -add new node at the beginning of the linked lidt
 * @str - new string to add in the node
 * return _ the address of teh new element, or NULL if fails
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	while (str[len])
		len++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->len = len;
	new->next = (*head);
	(*head) = new;

	return (*head);
}
