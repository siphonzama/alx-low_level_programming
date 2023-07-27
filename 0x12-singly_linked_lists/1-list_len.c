#include <stdio.h>
#include "lists.h"

/**
 * list_len - return the number of elements in linked list
 * @h - pointer to the list_t list
 * retrun - number of elements in h
*/

size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (i);
}
