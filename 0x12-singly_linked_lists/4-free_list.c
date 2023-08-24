#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Releases memory allocated for a linked list.
 * @head: Pointer to the list_t list to be deallocated.
 *
 * This function deallocates memory for a linked list, ensuring that both
 * the dynamically allocated strings within each node and the memory for
 * each node itself are properly freed.
 */
void free_list(list_t *head)
{
	list_t *temp;

	for (; head != NULL; head = temp)
	{
		temp = head->next;
		free(head->str);
		free(head);
	}
}
