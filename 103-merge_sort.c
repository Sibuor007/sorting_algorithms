#include "sort.h"

void sub_arr_merge(int *sub_arr, int *buff_, size_t head_, size_t mid, size_t tail);
void merge_recursive(int *sub_arr, int *buff_, size_t head_, size_t tail);
void merge_sort(int *array, size_t size);

/**
 * sub_arr_merge - func to sort a sub_array of integers.
 * @sub_arr: A sub_array of an array of integers
 * @buff_: A buffer to store the sorted sub_array     
 * @head_: The head_ index of the array
 * @mid: The middle index of the array
 * @tail: The tail index of the array
 */

void sub_arr_merge(int *sub_arr, int *buff_, size_t head_, size_t mid, size_t tail)
{
	size_t m, n, p = 0;

	printf("Merging \n[left]: ");
	print_array(sub_arr + head_, mid - head_);

	printf("[right]: ");
	print_array(sub_arr + mid, tail - mid);

	for (m = head_, n = mid; m < mid && n < tail; p++)
		buff_[p] = (sub_arr[m] < sub_arr[n]) ? sub_arr[m++] : sub_arr[n++];
	for (; m < mid; m++)
		buff_[p++] = sub_arr[m];
	for (; n < tail; n++)
		buff_[p++] = sub_arr[n];
	for (m = head_, p = 0; m < tail; m++)
		sub_arr[m] = buff_[p++];

	printf("[Done]: ");
	print_array(sub_arr + head_, tail - head_);
}

/**
 * merge_recursive - recursively implement the merge sort algorithm
 * @sub_arr: A sub_array of an array of integers
 * @buff_: A buffer to store the sorted result
 * @head_: The head_ index of the sub_array
 * @tail: The tail index of the sub_array
 */

void merge_recursive(int *sub_arr, int *buff_, size_t head_, size_t tail)
{
	size_t mid;

	if (tail - head_ > 1)
	{
		mid = head_ + (tail - head_) / 2;
		merge_recursive(sub_arr, buff_, head_, mid);
		merge_recursive(sub_arr, buff_, mid, tail);
		sub_arr_merge(sub_arr, buff_, head_, mid, tail);
	}
}

/**
 * merge_sort - func to sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 * Description: Implements the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buff_;

	if (array == NULL || size < 2)
		return;

	buff_ = malloc(sizeof(int) * size);
	if (buff_ == NULL)
		return;

	merge_recursive(array, buff_, 0, size);

	free(buff_);
}
