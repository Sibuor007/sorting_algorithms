#include "sort.h"

/**
 *  * swap_nodes - func to swap two integers
 *   * @var_0: The first num to swap.
 *    * @var_1: The second num to swap.
 *     */
void swap_nodes(int *var_0, int *var_1)
{
	int temp_;

	temp_ = *var_0;
	*var_0 = *var_1;
	*var_1 = temp_;
}

/**
 *  * selection_sort - func to sort an array in ascending order
 *   * @array: An array of numbers.
 *    * @size: The size of the array.
 *     * Description: Prints the array after every swap.
 *      */
void selection_sort(int *array, size_t size)
{
	int *min_;
	size_t item, k;

	if (array == NULL || size < 2)
		return;

	for (item = 0; item < size - 1; item++)
	{
		min_ = array + item;
		for (k = item + 1; k < size; k++)
			min_ = (array[k] < *min_) ? (array + k) : min_;

		if ((array + item) != min_)
		{
			swap_nodes(array + item, min_);
			print_array(array, size);
		}
	}
}
