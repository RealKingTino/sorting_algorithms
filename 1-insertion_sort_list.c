#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * @list: a doubly linked list pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *current;

	if (!list || !*list || !(*list)->next)
		return;
	current = (*list)->next;
	while (current)
	{
		sorted = current->prev;
		while (sorted && sorted->n > current->n)
		{
			if (sorted->prev) sorted->prev->next = current;
			if (current->next) current->next->prev = sorted;
			current->prev = sorted->prev;
			sorted->next = current->next;
			current->next = sorted;
			sorted->prev = current;
			sorted = current->prev;
			while ((*list)->prev) *list = (*list)->prev;
			print_list(*list);
		}
		current = current->next;
	}
	while ((*list)->prev) *list = (*list)->prev;
}
