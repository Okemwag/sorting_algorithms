#include "sort.h"

/**
 * _swap - swaps nodes of a list
 * maintain ascending order
 * @n1: first node
 * @n2: second node
 * @head: the head
 */
void _swap(listint_t *n1, listint_t *n2, listint_t **head)
{
	listint_t *t1, *t2;

	if (n1 == NULL || n2 == NULL)
		return;

	t1 = n1->prev;
	t2 = n2->next;

	if (t1)
		t1->next = n2;
	if (t2)
		t2->prev = n1;
	n1->next = t2;
	n1->prev = n2;
	n2->next = n1;
	n2->prev = t1;

	if (t1 == NULL)
		*head = n2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of ints using insertion
 * @list: Double pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = *list;

	while (current)
	{
		previous = current->prev;
		while (previous && previous->n > current->n)
		{
			_swap(previous, current, list);
			print_list(*list);
			previous = current->prev;
		}
		current = current->next;
	}
}

