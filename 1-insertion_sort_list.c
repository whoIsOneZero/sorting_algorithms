#include "sort.h"
/**
 * pos_in_sorted_list - positAOAions the new node in the `sorted_list`.
 * @head: a pointer to the head of the linked list
 * @new_node: the new node to add to the sorted list
 */

void pos_in_sorted_list(listint_t **head, listint_t *new_node)
{
	listint_t *current;

	/*If list is empty*/
	if (*head == NULL)
		*head = new_node;

	/*If the node is to be inserted at the beginning of the ...*/
	/*doubly linked list*/
	else if (new_node->n <= (*head)->n)
	{
		new_node->next = *head;  /*Send `new_node` before `head`*/
		new_node->next->prev = new_node; /*More like "head->prev = new_node".*/

		*head = new_node; /*`new_node` is the new head*/
	}

	else /*Insertion isn't at the beginning*/
	{
		current = *head;

		/*Locate the node after which new node is to be inserted*/
		while (current->next && current->next->n < new_node->n)
		{
			current = current->next;
		}

		/*The data in `current->next` > `new_node`*/
		/*So insert `new_node` before that node*/
		new_node->next = current->next;

		/*The new node is not inserted at the end*/
		if (current->next != NULL)
			new_node->next->prev = new_node;
		/*node after `new_node` should point to `new_node`*/

		/*Insert `new_node` after the current node*/
		current->next = new_node;
		new_node->prev = current;
	}
}


/**
 * insertion_sort_list - using Insertion sort, sort a doubly linked
 * list of integers in.
 *
 *@list: a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted_list = NULL; /*To hold the sorted portion*/
	listint_t *next;
	listint_t *ptr = *list; /*Start from the head*/

	/*Traverse current list and insert every node ...*/
	/*into the `sorted_list`*/

	while (ptr)
	{
		next = ptr->next; /*For next traversal*/

		/*de-link the `current` node for insertion into `sorted_list`*/
		ptr->prev = NULL;
		ptr->next = NULL;

		pos_in_sorted_list(&sorted_list, ptr);

		/*point to next node for next iteration*/
		ptr = next;
	}
	/*Inserted all nodes into the `sorted_list` linked list*/
	*list = sorted_list; /*update `list` to point to the new list*/
}
