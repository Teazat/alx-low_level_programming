#include "lists.h"

/**
 * sum_listint - Calculates the sum of all data in a listint_t linked list.
 * @head: Pointer to the first node in the linked list.
 *
 * Return: The sum of data values, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	for (temp = head; temp != NULL; temp = temp->next)
	{
		sum += temp->n;
	}

	return (sum);
}

