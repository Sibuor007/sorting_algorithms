#include "sort.h"

void swap_nodes(int *var_0, int *var_1);
int Partition(int *array, size_t size, int lower_b, int upper_b);
void lomuto_partition(int *array, size_t size, int lower_b, int upper_b);
void quick_sort(int *array, size_t size);

/**
 * swap_nodes - func to swap two integers in an array.
 * @var_0: The first integer to swap.
 * @var_1: The second integer to swap.
 */

void swap_nodes(int *var_0, int *var_1)
{
	int tmp;

	tmp = *var_0;
	*var_0 = *var_1;
	*var_1 = tmp;
}

/**
 * Partition - func to order a subset of an array of integers
 * @array: The array of integers.
 * @size: The size of the array.
 * @lower_b: The starting index of the subset
 * @upper_b: The ending index of the subset
 * Return: The final partition index.
 */

int Partition(int *array, size_t size, int lower_b, int upper_b)
{
	int *pivot, above_, below_;

	pivot = array + upper_b;
	for (above_ = below_ = lower_b; below_ < upper_b; below_++)
	{
		if (array[below_] < *pivot)
		{
			if (above_ < below_)
			{
				swap_nodes(array + below_, array + above_);
				print_array(array, size);
			}
			above_++;
		}
	}

	if (array[above_] > *pivot)
	{
		swap_nodes(array + above_, pivot);
		print_array(array, size);
	}

	return (above_);
}

/**
 * lomuto_partition - Implement the through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lower_b: The starting index of the array partition
 * @upper_b: The ending index of the array partition
 * Description: Uses the Lomuto partition
 */

void lomuto_partition(int *array, size_t size, int lower_b, int upper_b)
{
	int pivot_;

	if (upper_b - lower_b > 0)
	{
		pivot_ = Partition(array, size, lower_b, upper_b);
		lomuto_partition(array, size, lower_b, pivot_ - 1);
		lomuto_partition(array, size, pivot_ + 1, upper_b);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order 
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Lomuto partition scheme
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_partition(array, size, 0, size - 1);
}
