#include "sort.h"

/**
 * heap_sort - a function that sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, end;

	if (!array || size <= 1)
		return;

	for (i = (size / 2 - 1); i >= 0; i--)
		sift_down(array, i, size - 1, size);
	end = size - 1;
	while (end > 0)
	{
		swap(&array[0], &array[end]);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}

/**
 * sift_down - a function that sift array of integer
 * @array: an array of integer
 * @start: beginning of the array
 * @end: ending of the array
 * @size: size of the array
 */
void sift_down(int *array, int start, int end, size_t size)
{
	int root = start, child, s;

	while (leftChild(root) <= end)
	{
		child = leftChild(root);
		s = root;
		if (array[s] < array[child])
			s = child;
		if (child + 1 <= end && array[s] < array[child + 1])
			s = child + 1;
		if (s == root)
			return;
		swap(&array[root], &array[s]);
		print_array(array, size);
		root = s;
	}
}

/**
 * swap - a function that swaps two array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * leftChild - a function that finds the left Child in an array
 * @i: index
 * Return: an integer value
 */
int leftChild(int i)
{
	return (2 * i + 1);
}
