#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly link list in ascending order
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *iterator, *node_1, *node_2;

	if (list == NULL || (*list)->next == NULL)
		return;

	temp = *list;
	iterator = temp->next;

	while (iterator)
	{
		if (temp->n > iterator->n)
		{
			swap_nodes(temp, iterator);
			if (*list == temp)
				*list = iterator;
			iterator = iterator->next;
			temp = iterator->prev;
			print_list(*list);
			node_1 = temp;
			node_2 = node_1->prev;
			while (node_2 && node_2->n > node_1->n)
			{
				swap_nodes(node_2, node_1);
				if (node_2 == *list)
					*list = node_1;
				print_list(*list);
				node_2 = node_1->prev;
			}
		}
		temp = iterator;
		iterator = iterator->next;
	}
}

/**
 * node_swap - swap nodes on a dlinklist
 * @first: first node
 * @second: second node
 */

void swap_nodes(listint_t *first, listint_t *second)
{
	first->next = second->next;
	second->prev = first->prev;
	if (second->prev)
		second->prev->next = second;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	second->next = first;
}
