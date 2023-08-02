#include "lists.h"

/**
 * listint_len -return the number of elements
 * @h: used to traverse the linked list
 *
 * Return: the number of nodes
 *
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
