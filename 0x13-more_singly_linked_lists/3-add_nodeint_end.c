#include "lists.h"

/** 
 * a functionto a add a node at the end of list
 * @head: pointer to element one in list
 * @nn: used to insert the new element
 *
 * Return: pointer to new node or return NULL if fails
 *
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode;
	listint_t *temp = *head;

	newnode = malloc(sizeof(listint_t));
	if (!newnode)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}

	while(temp->next)
		temp = temp->next;

	temp->next = newnode;

	return (newnode);

}
