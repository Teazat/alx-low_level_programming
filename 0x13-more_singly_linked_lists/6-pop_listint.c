#include "lists.h"

/**
 * pop_listint - Removes and returns data of the head node of a linked list.
 * @head: Pointer to the first element in the linked list.
 *
 * Return: Data of the removed element, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *next_node;
	int data;

	if (!head || !*head)
		return (0);

	data = (*head)->n;
	next_node = (*head)->next;
	free(*head);
	*head = next_node;
	return (data);
}
