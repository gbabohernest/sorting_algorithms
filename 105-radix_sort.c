#include "sort.h"

int get_max(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);

/**
* get_max - Get the maximum element from an array.
* @array: The array of integers.
* @size: The size of the array.
* Return: The maximum element.
*/

int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
* count_sort - Perform counting sort on
* an array based on a significant digit.
* @array: The array of integers.
* @size: The size of the array.
* @exp: The current significant digit.
*/

void count_sort(int *array, size_t size, int exp)
{
	size_t i;
	int j, *output;
	int count[10] = {0};

	output = malloc(sizeof(int) * size);

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
* radix_sort - Sort an array of integers in
* ascending order using LSD Radix Sort.
* @array: The array to be sorted.
* @size: The size of the array.
*/

void radix_sort(int *array, size_t size)
{
	int max_value, exp;

	if (array == NULL || size < 2)
		return;

	max_value = get_max(array, size);

	for (exp = 1; max_value / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
