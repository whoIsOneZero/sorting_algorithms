#include "sort.h"

/**
 * selection_sort - sorts an array of (int), Selection sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	int temp, min_pos = 0;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	/*Does not sort an array with <2 elements*/
	for (a = 0; a < size - 1; a++)
	{
		min_pos = a;

		/*Start sorting from the element after the current ...*/
		/*... element at `min_pos`*/
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min_pos])
				min_pos = b;
		}

		if (min_pos != (int) a) /*Cases where a swap isn't necessary*/
		{
			temp = array[a];
			array[a] = array[min_pos];
			array[min_pos] = temp;
			print_array(array, size);
		}
	}
}
