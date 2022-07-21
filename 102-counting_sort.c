#include "sort.h"
#define RANGE 255
#include <string.h>

/**
 * counting_sort - a function that sorts using the counting sort algorithm
 *
 * @array: array to be sorted
 * @size: the size
 *
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *node, i, j, k;

	if (array == NULL || size < 2)
		return;

	node = malloc(sizeof(int) * ((int)size + 1));
	if (node == NULL)
		return;
	k = r_largest(array, size);
	counter = malloc(sizeof(int) * (k + 1));
	for (i = 0; i < k + 1; i++)
		counter[i] = 0;

	if (!counter)
	{
		free(node);
		return;
	}

	for (i = 0; i < (int)size; i++)
	{
		j = array[i];
		counter[j] += 1;
	}
	for (i = 1; i <= k + 1; i++)
		counter[i] += counter[i - 1];
	print_array(counter, k + 1);
	for (i = (int)size - 1; i >= 0; i--)
	{
		j = array[i];
		counter[j] -= 1;
		node[counter[j]] = array[i];
	}
	free(counter);
	copy_elements(array, node, size);
}


/**
 * r_largest - retrieves the largest element
 * @array: the array
 * @size: size of the array
 * Return: the largest number (int)
 */

int r_largest(int *array, size_t size)
{
	int i, b = 0;

	for (i = 0; i < (int)size; i++)
		b = b < array[i] ? array[i] : b;

	return (b);
}


/**
 * copy_elements - copy array2 elements into arra1
 * @arr1: second array
 * @arr2: first array
 * @size: size both arrays should be same size
 * Return: int 0
*/

int copy_elements(int *arr1, int *arr2, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		arr1[i] = arr2[i];

	free(arr2);
	return (0);
}
