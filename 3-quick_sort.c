#include "sort.h"

void _swap(int *num1, int *num2);
void recursion_quick_sort(int array[], int from, int to, size_t size);
int divide(int *array, int from, int to, size_t size);

/**
 * _swap - changes the position of the elements provided.
 * @num1: one element of the array to swap.
 * @num2: second element of the array to swap.
 */
void _swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * quick_sort - using Quick Sort, sorts an array of int.
 * @array: a pointer to the array.
 * @size: the size of the array.
 */
void quick_sort(int *array, size_t size)
{
	int length = size;

	if (array == NULL || size < 2)
		return;

	/*Initially works on the entire array*/
	recursion_quick_sort(array, 0, length - 1, size);
}

/**
 * recursion_quick_sort - does the divide and conquer in sorting process.
 * @array: the array to be sorted.
 * @from: where to start the partitioning from
 * @to: where to end the partitioning at
 * B
 * @size: the array size.
 */
void recursion_quick_sort(int array[], int from, int to, size_t size)
{
	int pivot_index;

	if (from < to)
	{
		pivot_index = divide(array, from, to, size);
		recursion_quick_sort(array, from, pivot_index - 1, size);
		recursion_quick_sort(array, pivot_index + 1, to, size);
	}
}

/**
 * divide - divides the array into small chunks for sorting (lamuto)
 * @array: the array to sort.
 * @from: where to start diving the array.
 * @to: where to stop dividing the array.
 * @size: the size of the array.
 *
 * Return: the index of the new pivot position
 */
int divide(int *array, int from, int to, size_t size)
{
	int *pivot_value = array + to; /*Pivot will always be last element*/
	int top, bottom, new_pivot_index;

	for (top = bottom = from; bottom < to; bottom++)
	{
		if (array[bottom] < *pivot_value)
		{
			if (top < bottom)
			{
				_swap(array + bottom, array + top);
				print_array(array, size); /*Show swap*/
			}
			top++; /*Next element*/
		}
	}

	if (array[top] > *pivot_value)
	{
		_swap(array + top, pivot_value);
		print_array(array, size); /*Show swap*/
	}

	new_pivot_index = top;

	return (new_pivot_index);
}
