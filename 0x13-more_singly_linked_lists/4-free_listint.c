#include "lists.h"

/**
 * a function that frees a listint_t list.
 *
 * @h: the list to be freed
 *
 */

void free_listint(listint_t *head)
{

	listint_t *node;
	
	while (head)
	{

		node = head->next;
		free(head);
		head = node;
	}

}
