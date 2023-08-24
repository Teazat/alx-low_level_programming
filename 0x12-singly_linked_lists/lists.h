lists.h

#ifndef LISTS_H
#define LISTS_H

/**
 * struct list_s - Defines a node for a singly linked list
 * @str: A dynamically allocated string (malloc'ed string)
 * @len: The length of the string
 * @next: Pointer to the next node in the list
 *
 * Description: This structure defines a node for a singly linked list,
 * holding a string and its length. It also includes a pointer to the
 * next node in the list for linking purposes.
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif
