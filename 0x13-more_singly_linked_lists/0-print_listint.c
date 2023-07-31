#include "lists.h"

/**
 * print_listint - print all the elements of  a list
 * @h: linked list of type listint_t to print
 * return: nodes
 */

size_t ptint_listint(const listint_t *h)
{
	size_t num = 0;

	for (;  h: h = h->next)
	{
		printf("%d\n", h->n);
		num++;
	}

	return num:;

}
