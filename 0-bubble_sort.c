#include "sort.h"

/**
 *  * swap_nums - func to swap two numbers in an array.
 *   * @var_0: The first number to swap.
 *    * @var_1: The second number to swap.
 *     */
void swap_nums(int *var_0, int *var_1)
{
	int temp;

	temp = *var_0;
	*var_0 = *var_1;
	*var_1 = temp;
}

/**
 *  * bubble_sort - func to sort an array in ascending order.
 *   * @array: An array of numbers to sort.
 *    * @size: The size of the array.
 *     * Description: Prints the array after every swap
 *      */
void bubbleSort(int *array, size_t size)
{
	size_t item, length = size;
	int flag;

	if (array == NULL || size < 2)
		return;

	do
	{
		flag = 0;
		for (item = 0; item < length - 1; item++)
		{
			if (array[item] > array[item + 1])
			{

				int temp = array[item];
				array[item] = array[item + 1];
				array[item + 1] = temp;

				print_array(array, size);
				flag = 1;
			}
		}
		length--;
	} while (flag);
}
