#include "lists.h"

/**
 * a function that returns the number of elements in a linked
 * @head: Pointer to the head od list
 * Return: Number  of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}
