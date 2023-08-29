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
	listint_t *current, *temp;

	if (!h || !*h)
		return (0);

	current = *h;

	while (current && current > current->next)
	{
		temp = current;
		current = current->next;
		free(temp);
		len++;
	}

	if (current)
	{
		free(current);
		len++;
	}

	*h = NULL;

	return (len);
}
