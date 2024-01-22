#include "sort.h"

void swap_nodes(int *var_0, int *var_1);
void heapify_max(int *array, size_t size, size_t base_node, size_t root_node);
void heap_sort(int *array, size_t size);

/**
 * swap_nodes - func to swap two integers
 * @var_0: The first integer to swap
 * @var_1: The second integer to swap
 */

void swap_nodes(int *var_0, int *var_1)
{
	int tmp;

	tmp = *var_0;
	*var_0 = *var_1;
	*var_1 = tmp;
}

/**
 * heapify_max - turns a binary tree into a complete binary heap.
 * @array: An array representing a binary tree.
 * @size: The size of the tree.
 * @base_node: The index of the base_node
 * @root_node: The root_node node
 */

void heapify_max(int *array, size_t size, size_t base_node, size_t root_node)
{
	size_t left_n, right_n, large_n;

	left_n = 2 * root_node + 1;
	right_n = 2 * root_node + 2;
	large_n = root_node;

	if (left_n < base_node && array[left_n] > array[large_n])
		large_n = left_n;
	if (right_n < base_node && array[right_n] > array[large_n])
		large_n = right_n;

	if (large_n != root_node)
	{
		swap_nodes(array + root_node, array + large_n);
		print_array(array, size);
		heapify_max(array, size, base_node, large_n);
	}
}

/**
 * heap_sort - func to sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after every swap
 */

void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = (size / 2) - 1; j >= 0; j--)
		heapify_max(array, size, size, j);

	for (j = size - 1; j > 0; j--)
	{
		swap_nodes(array, array + j);
		print_array(array, size);
		heapify_max(array, size, j, 0);
	}
}
