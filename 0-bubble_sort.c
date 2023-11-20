#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int temp;

	for (a = 0; a < size; a++)
	{
		/*To not go out of bound with array[b + 1]*/
		for (b = 0; b < size - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp = array[b + 1];
				array[b + 1] = array[b];
				array[b] = temp;
				print_array(array, size);
				/* print_array(NULL, 0); print a new line*/
			}
		}
	}
}
