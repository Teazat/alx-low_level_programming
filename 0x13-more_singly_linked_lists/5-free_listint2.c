#include "lists.h"

/**
 * free_listint2 - Frees a linked list.
 * @head: Pointer to the pointer pointing to the listint_t list to be freed.
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (!head)
		return;

	while (*head)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}

	*head = NULL;
}
