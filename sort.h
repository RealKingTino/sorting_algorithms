#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print Functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting Algorithms Functions */

void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap(int *a, int *b);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
int partition(int *array, size_t low, size_t high, int size);
void quick_sort_helper(int *array, int low, int high, size_t size);
void cocktail_sort_list(listint_t **list);
int traverse_back(listint_t *node, listint_t **list);
void swap(int *a, int *b);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, int start, int end, size_t size);
int leftChild(int i);
void merge_sort(int *array, size_t size);
void merge(int *array, int *lt, int *rt, size_t left_size, size_t right_size);
void merge_sort_helper(int *array, size_t size);

#endif /* SORT_H */
