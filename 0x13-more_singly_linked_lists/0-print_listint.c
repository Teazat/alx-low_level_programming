#include <stdio.h>
#include "lists.h"

/**
 * print_listint - Print all elements in a linked list.
 * @h: Pointer to the linked list of type listint_t.
 * Return: Number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
	size_t node_num = 0;

	for (; h != NULL; h = h->next)
	{
		printf("%d\n", h->n);
		node_num++;
	}

	return (node_num);
}
