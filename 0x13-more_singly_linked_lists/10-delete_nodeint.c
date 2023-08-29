#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at specific index in linked list.
 * @head: Pointer to a pointer pointing to the first element in the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *to_delete, *prev = NULL;

	if (!head || !*head)
		return (-1);

	if (index == 0)
	{
		to_delete = *head;
		*head = (*head)->next;
		free(to_delete);
		return (1);
	}

	prev = *head;
	for (i = 0; i < index - 1 && prev->next; i++)
		prev = prev->next;

	if (prev)
	{
		to_delete = prev->next;
		if (to_delete)
		{
			prev->next = to_delete->next;
			free(to_delete);
			return (1);
		}
	}

	return (-1);
}
