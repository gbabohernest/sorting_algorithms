#include "sort.h"

void swap(int *num1, int *num2);
/**
* bubble_sort - Sorts an array of integers
*		in assending order
* @array: Array to be sorted
* @size: Size of the array
*
* Return: Nothing (void)
*
* Description: Print the array after each swap
*	       of two elements
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, arr_len;

	if (array  == NULL || size < 2)
		return;

	arr_len = size;

	for (i = 0; i < arr_len - 1; i++)
	{
		int no_swap = 1;

		for (j = 0; j < arr_len - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				no_swap = 0;
			}
		}
		if (no_swap)
			break;
	}
}

/**
* swap - Swapping numbers in the array
* @num1: first number
* @num2: seconde number
*
* Description: Esay swapping of number for the
*	       implmentation of  bubble sort algorithm
*
*/

void swap(int *num1, int *num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
