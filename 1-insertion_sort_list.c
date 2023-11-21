#include "sort.h"

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
    listint_t *current = *list; /*Start from the head*/

    /*Traverse current list and insert every node ...*/
    /*into the `sorted_list`*/

    while(current)
    {
        next = current->next; /*For next traversal*/

        /*de-link the `current` node for insertion into `sorted_list`*/
        current->prev = NULL;
        current->next = NULL;

        pos_in_sorted_list(&sorted_list, current);

        /*point to next node for next iteration*/
        current = next;
    }
    /*Inserted all nodes into the `sorted_list` linked list*/
    *list = sorted; /*update `list` to point to the new list*/
}
