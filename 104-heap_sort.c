#include "sort.h"

void sift_down(int *array, size_t size, size_t root, size_t end);
void heapify(int *array, size_t size);

/**
* heap_sort - Sort an array of integers in ascending order using Heap Sort.
* @array: The array to be sorted.
* @size: The size of the array.
*/

void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);

	for (i = size - 1; i > 0; i--)
	{/*Swap the root(max element) with the last element*/
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;

		print_array(array, size);

		/*Heapify the reduced heap*/
		sift_down(array, size, 0, i);
	}
}

/**
* heapify - Build a max heap from an array.
* @array: The array to be transformed into a heap.
* @size: The size of the array.
*/

void heapify(int *array, size_t size)
{
	int i;

	/*Build a max heap*/
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);
}


/**
* sift_down - Perform a sift-down operation on the heap.
* @array: The array representing the heap.
* @size: The size of the array.
* @root: The root index of the subtree.
* @end: The end index of the heap.
*/

void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t largest, left_child, right_child;
	int tmp;

	largest = root;
	left_child = 2 * root + 1;
	right_child = 2 * root + 2;

	if (left_child < end && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < end && array[right_child] > array[largest])
		largest = right_child;

	if (largest != root)
	{
		tmp = array[root];
		array[root] = array[largest];
		array[largest] = tmp;

		print_array(array, size);

		sift_down(array, size, largest, end);
	}
}
