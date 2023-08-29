#include "lists.h"

/**
 * add_nodeint_end - Adds a node at the end of a linked list.
 * @head: Pointer to a pointer pointing to the first element in the list.
 * @n: Data to insert into the new node.
 *
 * Return: Pointer to the new node, or NULL if memory allocation fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *temp;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	temp = *head;
	while (temp->next)
		temp = temp->next;

	temp->next = new_node;

	return (new_node);
}
