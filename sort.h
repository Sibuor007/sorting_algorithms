#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros => bitonic sort */
#define UP_ 0
#define DOWN_ 1

/**
 * struct listint_s - the node to a doubly linked list*
 * @n: data stored in the node
 * @prev: previous pointer
 * @next: next pointer
 */

typedef struct listint_s
{
		const int n;
			struct listint_s *prev;
				struct listint_s *next;
} listint_t;

/* helper functions for printing */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* the sorting algoritms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* _SORT_H_ */
