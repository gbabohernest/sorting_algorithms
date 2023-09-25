#include "sort.h"

void swap(int *num1, int *num2);
int partition(int *array, int lb, int ub, size_t size);
void recursive_quick_sort(int *array, int lb, int ub);

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
* partition - Partition the array for quick
*	      sort using Lomuto partition scheme
* @array: Array to partition
* @lb: lower bound of the array
* @ub: upper bound of the array
* Return: The partition index
*/

int partition(int *array, int lb, int ub, size_t size)
{
	int pivot = array[ub];

	int i = lb - 1, j;

	for (j = lb; j <= ub - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	if (array[ub] < array[i + 1])
	{
		swap(&array[i + 1], &array[ub]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
* recursive_quick_sort - Quick sort function with Lomuto partition
* @array: Array to be sorted
* @lb: Lower bound of the array
* @ub: upper bound of the array
*/

void recursive_quick_sort(int *array, int lb, int ub)
{
	if (lb < ub)
	{
		int partition_index = partition(array, lb, ub, ub - lb + 1);
		/*sort left sub-array*/
		recursive_quick_sort(array, lb, partition_index - 1);
		/*sort right sub-array*/
		recursive_quick_sort(array, partition_index + 1, ub);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending
*	       order using the Quick sort algorithm
* @array: Array to be sorted
* @size: Size of the array.
*/

void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1);
}
