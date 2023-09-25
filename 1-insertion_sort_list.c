#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @prev: The previous node to be swapped
 * @curr: The current node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *prev, listint_t *curr)
{
	listint_t *next = curr->next;

	prev->next = next;
	if (next != NULL)
		next->prev = prev;

	curr->prev = prev->prev;
	curr->next = prev;
	prev->prev = curr;

	if (curr->prev == NULL)
		*list = curr;
	else
	curr->prev->next = curr;
}

/**
* insertion_sort_list - Sorts a doubly linked list of integers
*			in ascending order using the insertion
*			sort algorithm
* @list: Pointer to a pointer to the head of doubly linked list
*
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		/* DLL is already sorted or has one element */
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		listint_t *prev = curr->prev;
		listint_t *next_node = curr->next;

		while (prev != NULL && prev->n > curr->n)
		{
			swap_nodes(list, prev, curr);
			print_list(*list);
			prev = curr->prev;
		}

		curr = next_node;
	}
}
