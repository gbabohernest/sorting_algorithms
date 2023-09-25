#include "sort.h"

/**
* shell_sort - Sorts an array of integers in asending order using
*	       Shell sort algorithm, using the Knuth sequence.
* @array: Array to be sorted
* @size: Size of the array
*/

void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int i, j, tmp;

	if (array == NULL || size < 2)
		return;

	while (gap < (int)size / 3)
	{
		gap = gap * 3 + 1;
	}

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
