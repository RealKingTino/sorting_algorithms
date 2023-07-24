#include "sort.h"

/**
 * counting_sort - a function that sorts an array of integers in ascending
 * @array: an array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i = 0;
	int *count, *output, max_element, j = 0;

	if (size <= 1)
		return;
	max_element = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max_element) max_element = array[i];
	count = malloc(sizeof(int) * (max_element + 1));
	output = malloc(sizeof(int) * size);

	for (; j <= max_element; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j <= max_element; j++)
		count[j] += count[j - 1];
	print_array(count, max_element + 1);
	for (i = size - 1; i < (size_t)(-1); i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
