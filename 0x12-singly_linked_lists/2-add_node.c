#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Inserts a new node at the beginning of a linked list.
 * @head: Double pointer to the list_t list.
 * @str: New string to be added in the new node.
 *
 * Return: Address of the new element, or NULL on failure.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int len = 0;

	while (str[len])
		len++;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = len;
	new_node->next = (*head);
	(*head) = new_node;

	return (new_node);
}
