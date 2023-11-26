#include "sort.h"

/**
 * _swap - Interchange the postion of the two elements
 * @num1: the first element to switch
 * @num2: the second element to switch
 * Return: void
 */
void _swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * shell_sort - Using Shell sort, sort elements in ascending order
 * @array: the array (of int) to be sorted
 * @size: size of the array to be sorted.
 */
void shell_sort(int *array, size_t size)
{
	size_t dist; /*The interval or gap.*/
	size_t a, b;

	if (array == NULL || size < 2) /*Empty or one element*/
	{
		return;
	}

	for (dist = 1; dist < (size / 3);)
	{
		dist = dist * 3 + 1;
	}

	for (; dist >= 1; dist /= 3)
	{
		for (a = dist; a < size; a++)
		{
			b = a;
			while (b >= dist && array[b - dist] > array[b])
			{
				_swap(array + b, array + (b - dist));
				b -= dist;
			}
		}
		print_array(array, size); /*Show the swap*/
	}
}
