#include "lists.h"

/**
 * a function that returns the nth node of a listint_t linked list using get_nodeint_at-index
 * @head: first element of the list
 * @index: bring back index of the node
 *
 * Return: popinter to the node or NULL
 *
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int a = 0;
	listint_t *temp = head;

	while(temp && a < index)
	{
		temp = temp->next;
		a++;
	}

	return (temp ? temp : NULL);
}
