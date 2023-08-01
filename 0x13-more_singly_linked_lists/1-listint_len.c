#include "lists.h"

/**
 * a function that returns the number of elements in a linked
 * @head: Pointer to the head of list
 * Return: Number  of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t count num = 0;

	while (h)
	{
		count num++;
		h = h->next;
	}

	return (count num);
}
