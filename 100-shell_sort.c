#include "sort.h"
/**
 * shell_sort - a function that uses the shell sort algo to sort
 * @array: the array of items to sort
 * @size: sizeof the array
 */
void shell_sort(int *array, size_t size)
{
	int shell = 1, in, out, tmp;

	if (array == NULL || size < 2)
		return;
	while (shell <= ((int)size / 3))
		shell = (shell * 3) + 1;

	while (shell > 0)
	{
		for (out = shell; out < (int)size; out++)
		{
			tmp = array[out];
			in = out;
			while (in >= shell && array[in - shell] > tmp)
			{
				array[in] = array[in - shell];
				in = in - shell;
			}
			array[in] = tmp;
		}
		shell = (shell - 1) / 3;
		print_array(array, size);
	}
}
