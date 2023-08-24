#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Inserts a new node at the end of a linked list.
 * @head: Double pointer to the list_t list.
 * @str: String to be added in the new node.
 *
 * Return: Address of the new element, or NULL on failure.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = strlen(str);
	new_node->next = NULL;

	if (!*head)
		*head = new_node;
	else
	{
		list_t *temp = *head;

		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}

	return (new_node);
}
