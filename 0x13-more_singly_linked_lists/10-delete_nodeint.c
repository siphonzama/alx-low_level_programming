#include "lists.h"

/**
 * a function that deletes the node at index index of a listint_t linked list.
 * @head: pointer to first node
 * @index: index of the deleted node
 *
 * Return: 1 if success, or -1 if fail
 *
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{

	listint_t *temp = *head;
	listint_t *current = NULL;
	unsigned int a = 0;

	if (index == 0)
	{

		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (a < index -1)
	{  
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		a++;
	}

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
