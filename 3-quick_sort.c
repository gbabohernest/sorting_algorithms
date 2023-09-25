#include "sort.h"

/**
* swap - Swapping numbers in the array
* @num1: first number
* @num2: seconde number
*
* Description: Esay swapping of number for the
*	       implmentation of quick sort algorithm
*
*/
void swap(int *num1, int *num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
* lomuto_partition - Lomuto partition scheme
* @array: Array to be sorted
* @low: Starting index of the partition to be sorted
* @high: Ending index of the partition to be sorted
* @size: Size of the array
*
* Return: Index of the pivot element after partitioning
*/

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			if (i != j)
			{
				print_array(array, size);
			}
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	if (i + 1 != high)
	{
		print_array(array, size);
	}
	return (i + 1);
}

/**
* quicksort - Recursive function to perform quicksort
* @array: Array to be sorted
* @low: Starting index of the partition to be sorted
* @high: Ending index of the partition to be sorted
* @size: Size of the array
*/

void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in
*		ascending order using quicksort
 * @array: Array to be sorted
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
