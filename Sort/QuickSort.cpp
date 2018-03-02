#include "swap.hpp"

template <typename T>
ssize_t partition(T arr[], ssize_t start, ssize_t end) {
    T &pivot = arr[end];
    ssize_t tail = start - 1;
    for (size_t i=start; i < end; i++)
        if (arr[i] <= pivot)
            swap(arr, ++tail, i);
    swap(arr[tail+1], pivot);
    return tail+1;
}
template <typename T>
void quick_sort(T arr[], ssize_t start, ssize_t end) {
    if (start >= end)
        return;
    ssize_t pivot_index = partition(arr, start, end);
    quick_sort(arr, start, pivot_index-1);
    quick_sort(arr, pivot_index+1, end);
}

template <typename T>
void _sort(T arr[], size_t n) {
    quick_sort(arr, 0, n-1);
}
