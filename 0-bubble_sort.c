#include "sort.h"


/**
 * bubble_sort - a function that sorts an array
 *
 * @array: the array to be sorted
 * @size: size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size >= 2)
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(&array[j], &array[j + 1]);
					print_array(array, size);
				}
			}
		}
}

/**
 * swap - function that swaps two integers
 * @x: first to swap
 * @y: swapping with @y
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
