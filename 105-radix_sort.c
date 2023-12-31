#include "sort.h"

/**
 * count_sort - a function that sorts an array of integers in ascending
 * @array: an array
 * @size: size of the array
 * @exp: exponential in radix
 */
void count_sort(int *array, size_t size, int exp)
{
	size_t i = 0;
	int *count, *output, max_element, j = 0;

	if (size <= 1)
		return;
	max_element = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max_element)
			max_element = array[i];
	count = malloc(sizeof(int) * (max_element + 1));
	output = malloc(sizeof(int) * size);
	for (; j <= max_element; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (j = 1; j <= max_element; j++)
		count[j] += count[j - 1];
	for (i = size - 1; i < (size_t)(-1); i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}


/**
 * radix_sort - a function that sorts an array of integers in ascending order
 * @array: an array of integers
 * @size: the size of the element in an array
 */
void radix_sort(int *array, size_t size)
{
	int j, max_element;
	size_t i = 0;

	if (!array || size <= 1)
		return;
	max_element = array[0];
	for (; i < size; i++)
		if (array[i] > max_element)
			max_element = array[i];
	for (j = 1; max_element / j > 0; j *= 10)
	{
		count_sort(array, size, j);
		print_array(array, size);
	}
}
