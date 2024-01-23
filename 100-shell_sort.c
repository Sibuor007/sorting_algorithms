#include "sort.h"

/**
 * swap_nodes - func to swap two integers
 * @var_0: The first integer to swap.
 * @var_1: The second integer to swap.
 */
void swap_nodes(int *var_0, int *var_1)
{
	int temp;

	temp = *var_0;
	*var_0 = *var_1;
	*var_1 = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 * Description: Uses the Knuth interval sequence
 */

void shell_sort(int *array, size_t size)
{
	size_t gap_, m, n;

	if (array == NULL || size < 2)
		return;

	for (gap_ = 1; gap_ < (size / 3);)
		gap_ = gap_ * 3 + 1;

	for (; gap_ >= 1; gap_ /= 3)
	{
		for (m = gap_; m < size; m++)
		{
			n = m;
			while (n >= gap_ && array[n - gap_] > array[n])
			{
				swap_nodes(array + n, array + (n - gap_));
				n -= gap_;
			}
		}
		print_array(array, size);
	}
}
