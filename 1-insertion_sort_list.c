#include "sort.h"

/**
 * nodes_switch - Swap two nodes in a listint_t doubly-linked list.
 * in descending order. smaller elements to the left.
 *
 * @head: A pointer to the head of the doubly-linked list.
 * @big: a ptr to the node with larger `n` (data).
 * @small: a ptr to the node with smaller `n` (data).
 */
void nodes_switch(listint_t **head, listint_t **big, listint_t *small)
{
	(*big)->next = small->next;
	if (small->next != NULL)  /*Not the last node*/
		small->next->prev = *big; /*node3 point back to node1*/

	small->prev = (*big)->prev;  /*point to node b4 node1*/
	small->next = *big;

	if ((*big)->prev != NULL) /*not the first node (head)*/
		(*big)->prev->next = small; /*node0 point to small*/
	else
		*head = small;
	(*big)->prev = small;
	*big = small->prev;
}

/**
 * insertion_sort_list - unsing Insertion Sort, sort a doubly linked
 * list of integers.
 *
 * @list: a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *ptr, *insert;
	listint_t *node; /*Keeps track of the current node*/

    /*List is empty*/
	if (list == NULL || *list == NULL || (*list)->next == NULL) /*or one node*/
		return;

	for (node = (*list)->next; node != NULL; node = ptr)
	{
		ptr = node->next;
		insert = node->prev;
		while (insert != NULL && node->n < insert->n)
		{
			nodes_switch(list, &insert, node);
			print_list((const listint_t *)*list);
		}
	}
}
