0x1B. C - Sorting algorithms & Big O
[tests] this is the folder test files

[print_array.c] function to be used to print array of integers
[print_list.c] function used to print a doubly linked list

[sort.h] header file that contains all prototypes and definitions for all functions and types

Data structures

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

Function prototypes

| `print_array.c`            | `void print_array(const int *array, size_t size)` |
| `print_list.c`             | `void print_list(const listint_t *list)`          |
| `0-bubble_sort.c`          | `void bubble_sort(int *array, size_t size);`      |
| `1-insertion_sort_list.c`  | `void insertion_sort_list(listint_t **list);`     |
| `2-selection-sort.c`       | `void selection_sort(int *array, size_t size);`   |
| `3-quick_sort.c`           | `void quick_sort(int *array, size_t size);`       |
| `100-shell_sort.c`         | `void shell_sort(int *array, size_t size);`       |
| `101-cocktail_sort_list.c` | `void cocktail_sort_list(listint_t **list);`      |
| `102-counting_sort.c`      | `void counting_sort(int *array, size_t size);`    |
| `103-merge_sort.c`         | `void merge_sort(int *array, size_t size);`       |
| `104-heap_sort.c`          | `void heap_sort(int *array, size_t size);`        |
| `105-radix_sort.c`         | `void radix_sort(int *array, size_t size);`       |
| `106-bitonic_sort.c`       | `void bitonic_sort(int *array, size_t size);`     |
| `107-quick_sort_hoare.c`   | `void quick_sort_hoare(int *array, size_t size);` |

Data structures
