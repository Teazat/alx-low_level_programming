#include "lists.h"

/**
 * free_listint_safe - Frees a linked list and handles looped lists.
 * @h: Pointer to a pointer pointing to the first node in the linked list.
 *
 * Return: Number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *current, *next;

	if (!h)
		return (0);

	current = *h;

	while (current)
	{
		if (current <= current->next)
		{
			next = current->next;
			free(current);
			*h = NULL;
			len++;
			break;
		}

		next = current->next;
		free(current);
		current = next;
		len++;
	}

	return (len);
}
