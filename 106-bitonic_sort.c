#include "sort.h"

void swap_nodes(int *var_0, int *var_1);
void merge_bitonic(int *array, size_t size, size_t head_, size_t sequence, char direction);
void seq_bitonic(int *array, size_t size, size_t head_, size_t sequence, char direction);
void bitonic_sort(int *array, size_t size);

/**
 * swap_nodes - func to swap two integers
 * @a: The first integer to swap
 * @b: The second integer to swap
 */

void swap_nodes(int *var_0, int *var_1)
{
	int temp;

	temp = *var_0;
	*var_0 = *var_1;
	*var_1 = temp;
}

/**
 * merge_bitonic - func to sort a bitonic sequence inside an array
 * @array: An array of integers
 * @size: The size of the array
 * @head_: The starting index of the sequence
 * @sequence: The size of the sequence
 * @direction: The direction to sort in
 */

void merge_bitonic(int *array, size_t size, size_t head_, size_t sequence,
		char direction)
{
	size_t k, fwd = sequence / 2;

	if (sequence > 1)
	{
		for (k = head_; k < head_ + fwd; k++)
		{
			if ((direction == UP_ && array[k] > array[k + fwd]) ||
					(direction == DOWN_ && array[k] < array[k + fwd]))
				swap_nodes(array + k, array + k + fwd);
		}
		merge_bitonic(array, size, head_, fwd, direction);
		merge_bitonic(array, size, head_ + fwd, fwd, direction);
	}
}

/**
 * seq_bitonic - func to convert an array
 * @array: An array of integers
 * @size: The size of the array
 * @head_: The starting index of a block of the bitonic sequence
 * @sequence: The size of a block
 * @direction: The direction to sort
 */

void seq_bitonic(int *array, size_t size, size_t head_, size_t sequence, char direction)
{
	size_t res_ = sequence / 2;
	char *str_n = (direction == UP_) ? "UP_" : "DOWN_";

	if (sequence > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequence, size, str_n);
		print_array(array + head_, sequence);

		seq_bitonic(array, size, head_, res_, UP_);
		seq_bitonic(array, size, head_ + res_, res_, DOWN_);
		merge_bitonic(array, size, head_, sequence, direction);

		printf("Result [%lu/%lu] (%s):\n", sequence, size, str_n);
		print_array(array + head_, sequence);
	}
}

/**
 * bitonic_sort - func to sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 * Description: Prints the array after every swap
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	seq_bitonic(array, size, 0, size, UP_);
}
