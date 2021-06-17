#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y, limit = 0;
	int temp = 0;

	if (size < 2)
		return;

	for (x = 0; x < size; x++)
		for (y = 0, limit = size - x - 1; y < limit; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
		}
}
