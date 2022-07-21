#include "sort.h"


/**
 * selection_sort - a function that sorts an array
 *
 * @array: the array to be sorted
 * @size: size of the array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int comp;

	if (size >= 2)
	{
		for (i = 0; i < size; i++)
		{
			comp = array[i];
			min = i;

			for (j = i; j < size; j++)
			{
				if (comp > array[j])
				{
					min = j;
					comp = array[j];
				}
			}
			if (comp == array[i] && min == i)
				continue;
			/*else, swap*/
			array[min] = array[i];
			array[i] = comp;
			print_array(array, size);
		}
	}
}
