#include "lists.h"

/**
 * a function that adds a new node at the beginning of a listint_t list.
 * @h: pointer to the first node
 * @nn: pointer  to insert the new node
 * Return: a pointer to the new node or NULL should be it fail
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

		newnode = malloc(sizeof(listint_t));
			if (!newnode)
				return (NULL);

		newnode->n = n;
		newnode->next = *head;
		*head = newnode;

		return (newnode);

}
