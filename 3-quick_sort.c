#include "sort.h"
/**
 * quick_sort - a function that sorts an array of integer
 * @array: an array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quick_sort_helper(array, 0, size - 1, size);
}

/**
 * partition - a function that find the partition of an array
 * @array: an array to partition
 * @low: low bound of the  array
 * @high: high bound of the array
 * @size: size of the array
 * Return: the pivot of the array
 */
int partition(int *array, size_t low, size_t high, int size)
{
	int pivot = array[high], i = low;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * swap - function that swap to element in an array
 * @a: first element
 * @b: second element
 *
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort_helper - helps with assigning high and low
 * @low: beginning of array
 * @high: end of the array
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}
