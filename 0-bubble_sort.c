#include "sort.h"

/**
 * bubble_sort - func to sort an array in ascending order.
 * @array: An array of numbers to sort.
 * @size: The size of the array.
 * Description: Prints the array after every swap
 */

void bubbleSort(int *array, size_t size)
{
	size_t j, length = size;
	int k, temp;
	int flag;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < length - 1; j++)
	{
		flag = 0;
		for (k = 0; k < length - 1 - j; k++)
		{

			if (array[k] > array[k + 1])
			{

				temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;

				print_array(array, size);
				flag = 1;
			}
		}
		length--;
		if (flag == 0)
			break;
	}
}
