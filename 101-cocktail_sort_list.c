#include "sort.h"

void swap_node_next(listint_t **list, listint_t **tail_, listint_t **shaker_);
void swap_node_prev(listint_t **list, listint_t **tail_, listint_t **shaker_);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_next - Swap a node in a list with the node ahead of it
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail_: A pointer to the tail_ of the doubly-linked list.
 * @shaker_: A pointer to the current swapping node
 */

void swap_node_next(listint_t **list, listint_t **tail_, listint_t **shaker_)
{
	listint_t *temp = (*shaker_)->next;

	if ((*shaker_)->prev != NULL)
		(*shaker_)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker_)->prev;
	(*shaker_)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker_;
	else
		*tail_ = *shaker_;
	(*shaker_)->prev = temp;
	temp->next = *shaker_;
	*shaker_ = temp;
}

/**
 * swap_node_prev - func to swap node in a linked list with the node behind it
 * @list: A pointer to the head of a doubly-linked list
 * @tail_: A pointer to the tail_ of the doubly-linked list.
 * @shaker_: A pointer to the current swapping node
 */

void swap_node_prev(listint_t **list, listint_t **tail_, listint_t **shaker_)
{
	listint_t *temp = (*shaker_)->prev;

	if ((*shaker_)->next != NULL)
		(*shaker_)->next->prev = temp;
	else
		*tail_ = temp;
	temp->next = (*shaker_)->next;
	(*shaker_)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker_;
	else
		*list = *shaker_;
	(*shaker_)->next = temp;
	temp->prev = *shaker_;
	*shaker_ = temp;
}

/**
 * cocktail_sort_list - func to sort a doubly-linked list of
 * integers in ascending order
 * @list: A pointer to the head of a doubly-linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail_, *shaker_;
	int flag_ = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail_ = *list; tail_->next != NULL;)
		tail_ = tail_->next;

	while (flag_ == 0)
	{
		flag_ = 1;
		for (shaker_ = *list; shaker_ != tail_; shaker_ = shaker_->next)
		{
			if (shaker_->n > shaker_->next->n)
			{
				swap_node_next(list, &tail_, &shaker_);
				print_list((const listint_t *)*list);
				flag_ = 0;
			}
		}
		for (shaker_ = shaker_->prev; shaker_ != *list;
				shaker_ = shaker_->prev)
		{
			if (shaker_->n < shaker_->prev->n)
			{
				swap_node_prev(list, &tail_, &shaker_);
				print_list((const listint_t *)*list);
				flag_ = 0;
			}
		}
	}
}
