#include "sort.h"

void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2);

/**
* cocktail_sort_list - sorts a doubly linked list of integer using
* cocktail shaker sort, list is sorted in ascending order.
* @list: pointer to head of listint_t doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = NULL;
	listint_t *right = NULL;
	listint_t *current;
	int swapped;

	if (!list || !*list || !(*list)->next)
		return;
	do {
		swapped = 0;
		current = *list;

		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				swapped = 1;
				if (!current->prev)
					*list = current;
				print_list(*list);
			}
			else
				current = current->next;
		}
		right = current;
		if (!swapped)
			break;
		swapped = 0;
		current = right;
		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &(current->prev), &current);
				swapped = 1;
				if (!current->prev)
					*list = current;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		left = current;
	} while (swapped);
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to head of full list
 * @node1: pointer to the first node to be swapped
 * @node2: pointer to the second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *temp1 = *node1;
	listint_t *temp2 = *node2;

	if (temp1->prev)
		temp1->prev->next = temp2;
	else
		*list = temp2;

	if (temp2->next)
		temp2->next->prev = temp1;

	temp1->next = temp2->next;
	temp2->prev = temp1->prev;
	temp1->prev = temp2;
	temp2->next = temp1;
}
