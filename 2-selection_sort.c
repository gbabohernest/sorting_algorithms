#include "sort.h"

void swap(int *num1, int *num2);
/**
* selection_sort - Sorts an array of integers in asending
*		   order using the selection sort algorithm
* @array: Array to be sorted
* @size: Size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, arr_len;

	if (array == NULL || size < 2)
		return;

	arr_len = size;

	for (i = 0; i < arr_len - 1; i++)
	{
		size_t min_integer = i;

		for (j = i + 1;  j < arr_len; j++)
		{
			/*comparision*/
			if (array[j] < array[min_integer])
			{
				min_integer = j;
			}
		}
		if (min_integer != i)
		{
			swap(&array[i], &array[min_integer]);
			print_array(array, size);
		}
	}
}

/**
* swap - Swapping numbers in the array
* @num1: first number
* @num2: seconde number
*
* Description: Esay swapping of number for the
*	       implmentation of selection sort algorithm
*
*/

void swap(int *num1, int *num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
