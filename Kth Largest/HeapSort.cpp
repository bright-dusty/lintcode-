#include "swap.hpp"

template <typename T>
void heapify(T arr[], size_t p_index, size_t h_size) {
	size_t l_index = p_index * 2 + 1, 
		   r_index = p_index * 2 + 2;
	size_t max_index = p_index;
	if (l_index < h_size && arr[l_index] > arr[max_index])
		max_index = l_index;
	if (r_index < h_size && arr[r_index] > arr[max_index])
		max_index = r_index;
	if (max_index != p_index) {
		swap(arr, p_index, max_index);
		heapify(arr, max_index, h_size);
	}
	
}

template <typename T>
void build_heap(T arr[], size_t n) {
	for (ssize_t i=n/2-1; i >= 0; i--)
		heapify(arr, i, n);
}

template <typename T>
void _sort(T arr[], size_t n) {
	size_t heap_size = n;
	build_heap(arr, n); 
	while (heap_size > 1) {
		swap(arr, 0, --heap_size);
		heapify(arr, 0, heap_size);
	}
}
