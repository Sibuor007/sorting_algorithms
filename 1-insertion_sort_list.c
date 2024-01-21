#include "sort.h"

/**
 *  * swap_l_list - func to swap two nodes
 *   * @head: A pointer to the head of the list.
 *    * @node_0:  the first node to swap.
 *     * @node_1: the second node to swap.
 *      */

void swap_l_list(listint_t **head, listint_t **node_0, listint_t *node_1)
{
	if (!head || !*head || !node_0 || !*node_0 || !node_1 || *node_0 == node_1)
		return;

	listint_t *temp = node_1->next;

	(*node_0)->next = temp;
	node_1->next = *node_0;

	if (temp)
		temp->prev = *node_0;
	if ((*node_0)->next)
		(*node_0)->next->prev = node_1;

	temp = node_1->prev;
	node_1->prev = (*node_0)->prev;
	(*node_0)->prev = temp;

	if (node_1->prev)
		node_1->prev->next = node_1;
	else
		*head = node_1;
	if ((*node_0)->prev)
		(*node_0)->prev->next = *node_0;

	*node_0 = node_1;
}

/**
 *  * insertion_sort_list - Sorts a doubly linked list of integers
 *   * @list: A pointer to the head of a list
 *    * Description: Prints the list after every swap.
 *     */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr_, *ptr_, *temp_;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr_ = (*list)->next; curr_ != NULL; curr_ = temp_)
	{
		temp_ = curr_->next;
		ptr_ = curr_->prev;
		while (ptr_ != NULL && curr_->n < ptr_->n)
		{
			swap_l_list(list, &ptr_, curr_);
			print_list((const listint_t *)*list);
		}
	}
}
