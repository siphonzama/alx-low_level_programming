#include "lists.h"

/**
 * a function that returns the number of elements in a linked
 * @h: return the number of elements in a list
 * Return: count
 */

typedef struct listint_s
{ 
	int data;
	struct listint_s *next;
}

listint_t;

size_t listint_len(const listint_t *h);
{
	size_t count = 0;

	for(const listint_t *current = head;
			current != NULL; current = current->next)
	{
		count++;
	}
	return count;
}
