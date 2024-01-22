#include "sort.h"

int max_value(int *array, int size);
void radix_counting(int *array, size_t size, int sig_digit, int *buff_er);
void radix_sort(int *array, size_t size);

/**
 * max_value - Get the maximum value in an array
 * @array: An array of integers
 * @size: The size of the array
 * Return: The maximum integer in the array
 */
int max_value(int *array, int size)
{
	int max_v, j;

	for (max_v = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max_v)
			max_v = array[j];
	}

	return (max_v);
}

/**
 * radix_counting - func sort the sig_dig of an array of integers in ascending order 
 * @array: An array of integers
 * @size: The size of the array
 * @sig_digit: The significant digit to sort on
 * @buff_er: A buffer to store the sorted array
 */

void radix_counting(int *array, size_t size, int sig_digit, int *buff_er)
{
	int count_[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t j;

	for (j = 0; j < size; j++)
		count_[(array[j] / sig_digit) % 10] += 1;

	for (j = 0; j < 10; j++)
		count_[j] += count_[j - 1];

	for (j = size - 1; (int)j >= 0; j--)
	{
		buff_er[count_[(array[j] / sig_digit) % 10] - 1] = array[j];
		count_[(array[j] / sig_digit) % 10] -= 1;
	}

	for (j = 0; j < size; j++)
		array[j] = buff_er[j];
}

/**
 * radix_sort - func to sort an array of integers in ascending order 
 * @array: An array of integers
 * @size: The size of the array
 * Description: Implements the radix sort algorithm
 */

void radix_sort(int *array, size_t size)
{
	int max_v, sig_digit, *buff_er;

	if (array == NULL || size < 2)
		return;

	buff_er = malloc(sizeof(int) * size);
	if (buff_er == NULL)
		return;

	max_v = max_value(array, size);
	for (sig_digit = 1; max_v / sig_digit > 0; sig_digit *= 10)
	{
		radix_counting(array, size, sig_digit, buff_er);
		print_array(array, size);
	}

	free(buff_er);
}
