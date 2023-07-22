#include "sort.h"
/**
 * cocktail_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order
 * @list: linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;
	do {
		swapped = 0, current = *list;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				if (current->prev)
					current->prev->next = current->next;
				else
					*list = current->next;
				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;
				if (current->next)
					current->next->prev = current;
				current->prev->next = current;
				swapped = 1;
				while ((*list)->prev)
					*list = (*list)->prev;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		current = current->prev;
		swapped = traverse_back(current, list);
	} while (swapped);
	while ((*list)->prev)
		*list = (*list)->prev;
}

/**
 * traverse_back - traverse backward and swap nodes
 * @node: node to swap
 * @list: node header
 * Return: an integer value for swap
 */
int traverse_back(listint_t *node, listint_t **list)
{
	int swapped;

	while (node->prev)
	{
		if (node->n < node->prev->n)
		{
			if (node->next)
				node->next->prev = node->prev;
			else
				*list = node->prev;
			node->prev->next = node->next;
			node->next = node->prev;
			node->prev = node->prev->prev;
			if (node->prev)
				node->prev->next = node;
			node->next->prev = node;
			swapped = 1;
			while ((*list)->prev)
				*list = (*list)->prev;
			print_list(*list);
		}
		else
			node = node->prev;
	}
	return (swapped);
}
