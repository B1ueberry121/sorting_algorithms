#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * @array: array of integers to sort
 * @size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t x, y, temp = 0;
	int hold = 0, flag = 0;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size; x++)
	{
		temp = x;
		flag = 0;

		for (y = x + 1; y < size; y++)
		{
			if (array[temp] > array[y])
			{
				temp = y;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			hold = array[x];
			array[x] = array[temp];
			array[temp] = hold;
			print_array(array, size);
		}
	}
}
