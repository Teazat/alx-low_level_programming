#include "lists.h"

/**
 * get_nodeint_at_index - Returns node at a specific index in a linked list.
 * @head: Pointer to the first node in the linked list.
 * @index: Index of the node to retrieve.
 *
 * Return: Pointer to the node at the specified index, or NULL if not found.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current = head;

	for (i = 0; current && i < index; i++)
	{
		current = current->next;
	}

	return (current ? current : NULL);
}
