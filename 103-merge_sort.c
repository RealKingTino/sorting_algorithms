#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_helper(array, size);
}

/**
 * merge_sort_helper - Helper function for the Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort_helper(int *array, size_t size)
{
	size_t mid;
	size_t left_size, right_size;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;
	left_size = mid;
	right_size = size - mid;

	left = array;
	right = array + mid;

	merge_sort_helper(left, left_size);
	merge_sort_helper(right, right_size);
	merge(array, left, right, left_size, right_size);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge - Merges two sorted arrays into one sorted array.
 * @array: The destination array to hold the merged result.
 * @lt: The left sorted array.
 * @rt: The right sorted array.
 * @left_size: The number of elements in the left array.
 * @right_size: The number of elements in the right array.
 */
void merge(int *array, int *lt, int *rt, size_t left_size, size_t right_size)
{
	size_t left_idx, right_idx, temp_idx;
	size_t total_size = left_size + right_size;
	int *temp = (int *)malloc(total_size * sizeof(int));

	if (temp == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}

	left_idx = right_idx = temp_idx = 0;

	while (left_idx < left_size && right_idx < right_size)
	{
		if (lt[left_idx] <= rt[right_idx])
			temp[temp_idx++] = lt[left_idx++];
		else
			temp[temp_idx++] = rt[right_idx++];
	}

	while (left_idx < left_size)
		temp[temp_idx++] = lt[left_idx++];

	while (right_idx < right_size)
		temp[temp_idx++] = rt[right_idx++];

	for (temp_idx = 0; temp_idx < total_size; temp_idx++)
		array[temp_idx] = temp[temp_idx];

	free(temp);
}
