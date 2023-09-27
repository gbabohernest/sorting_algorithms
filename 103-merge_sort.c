#include "sort.h"

void merge(int *array, int *tmp_arr, size_t left, size_t mid, size_t right);
void merge_sort_helper(int *array, int *tmp_arr, size_t left, size_t right);

/**
* merge - Merge two sorted subarrays into one.
* @array: The original array.
* @tmp_arr: An array to temporarily store the merged subarrays.
* @left: The start index of the first subarray
* @mid: The end index of the first subarray(exclusive)
* @right: The end index of the second subarray(exclusive)
*/

void merge(int *array, int *tmp_arr, size_t left, size_t mid, size_t right)
{
	size_t  i, j, k;

	i = left;
	j = mid;
	k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
		{
			tmp_arr[k++] = array[i++];
		}
		else
		{
			tmp_arr[k++] = array[j++];
		}
	}
	while (i < mid)
		tmp_arr[k++] = array[i++];
	while (j < right)
		tmp_arr[k++] = array[j++];

	for (i = left, k = 0; i < right; i++)
		array[i] = tmp_arr[k++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
* merge_sort_helper - Recursively divide and merge the array.
* @array: The original array.
* @tmp_arr: A array to temporarily store merged subarrays.
* @left: The start index of the subarray to be sorted.
* @right: The end index of the subarray to be sorted (exclusive).
*/
void merge_sort_helper(int *array, int *tmp_arr, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;

	/*Recursivley sort and merge both left and right halves*/
	merge_sort_helper(array, tmp_arr, left, mid);
	merge_sort_helper(array, tmp_arr, mid, right);
	merge(array, tmp_arr, left, mid, right);
}

/**
* merge_sort - Sorts an array in ascending order using
* the top-down merge sort algorithm and prints each merge step.
* @array: The array to be sorted.
* @size: The size of the array.
*/

void merge_sort(int *array, size_t size)
{
	int *tmp_arr;

	if (array == NULL || size < 2)
		return; /*Nothing to sort*/


	tmp_arr = malloc(sizeof(int) * size);

	if (tmp_arr == NULL)
		return;

	merge_sort_helper(array, tmp_arr, 0, size);
	free(tmp_arr);
}
