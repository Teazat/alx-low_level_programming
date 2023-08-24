#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Returns the number of elements in a linked list
 * @h: Pointer to the list_t list
 *
 * Return: Number of elements in the linked list
 */
size_t list_len(const list_t *h)
{
	size_t n;

	for (n = 0; h; n++, h = h->next)
	;

	return (n);
}
