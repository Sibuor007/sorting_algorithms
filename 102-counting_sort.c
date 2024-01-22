#include "sort.h"

/**
 * max_value - func to get the maximum value
 * @array: An array of integers
 * @size: The size of the array
 * Return: The maximum integer in the array.
 */

int max_value(int *array, int size)
{
	int max_v, i;

	for (max_v = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_v)
			max_v = array[i];
	}

	return (max_v);
}

/**
 * counting_sort - func to sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 * Description: Prints the counting array afterward
 */

void counting_sort(int *array, size_t size)
{
	int *count_s, *sorted_arr, max_v, i;

	if (array == NULL || size < 2)
		return;

	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
		return;
	max_v = max_value(array, size);
	count_s = malloc(sizeof(int) * (max_v + 1));
	if (count_s == NULL)
	{
		free(sorted_arr);
		return;
	}

	for (i = 0; i < (max_v + 1); i++)
		count_s[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_s[array[i]] += 1;
	for (i = 0; i < (max_v + 1); i++)
		count_s[i] += count_s[i - 1];
	print_array(count_s, max_v + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_arr[count_s[array[i]] - 1] = array[i];
		count_s[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_arr[i];

	free(sorted_arr);
	free(count_s);
}
