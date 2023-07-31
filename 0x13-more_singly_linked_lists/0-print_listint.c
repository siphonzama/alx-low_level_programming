#include "lists.h"
#include <stdio.h>

/**
 * print_listint - print all the elements of  a list
 * @h: linked list of type listint_t to print
 * return: nodes
 */

size_t print_listint(const listint_t *h);
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next
	}

	return (num);

}
