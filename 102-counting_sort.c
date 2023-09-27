#include "sort.h"

/**
* counting_sort - Sorts an array of integers in ascending
*		order using Counting Sort Algorithm
* @array: Array to be sorted
* @size: Size of the array
*/

void counting_sort(int *array, size_t size)
{
	int max, *counting_array, *tmp_array, k, idx;
	size_t i;
	ssize_t j;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++) /*Find max value in the array*/
	{
		if (array[i] > max)
			max = array[i];
	}

	counting_array = malloc(sizeof(int) * (max + 1)); /*create a counting array*/
	if (counting_array == NULL)
		return;
	for (k = 0; k <= max; k++) /*init zero to counting_array*/
		counting_array[i] = 0;
	for (i = 0; i < size; i++) /*count elements occurrences in the input array*/
		counting_array[array[i]]++;
	for (k = 1; k <= max; k++) /*update counting array*/
		counting_array[k] += counting_array[k - 1];
	print_array(counting_array, max + 1);

	tmp_array = malloc(sizeof(int) * size);/*temp array to hold sorted elements*/
	if (tmp_array == NULL)
	{
		free(counting_array);
		return;
	}
	for (j = size - 1; j >= 0; j--) /*add the sorted elements  into tmp array*/
	{
		idx = counting_array[array[j]] - 1;
		tmp_array[idx] = array[j];
		counting_array[array[j]]--;
	}
	for (i = 0; i < size; i++) /*copy sorted elements back to the input array*/
		array[i] = tmp_array[i];
	free(counting_array);
	free(tmp_array);
}
