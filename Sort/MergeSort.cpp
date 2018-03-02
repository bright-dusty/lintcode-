#include <exception>
#include <stdexcept>
#include <new>
#include <typeinfo>
#include <iostream>

template <typename T>
void merge(T arr[], size_t start, 
    size_t mid, size_t end, T temp[]) 
{
    size_t i = start,
           j = mid + 1,
           k = 0;
    while (i <= mid && j <= end)
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];
    
    for (i=0; i < k; i++)
        arr[start+i] = temp[i];
}

template <typename T>
void merge_sort_recursive(T arr[], size_t start, 
                size_t end, T temp[]) 
{
    if (start == end)
        return;
    size_t mid = (start + end) / 2;
    merge_sort_recursive(arr, start, mid, temp);
    merge_sort_recursive(arr, mid+1, end, temp);
    merge(arr, start, mid, end, temp);
}


template <typename T> 
void merge_sort(T arr[], size_t n, T temp[]) {
    size_t half = 1; // half span
    for (; half < n; half *= 2) {
        size_t start = 0;
        while (start+half < n) {
            size_t mid = start + half - 1;
            size_t end = mid + half < n ? mid + half : n - 1;
            merge(arr, start, mid, end, temp);
            start = end + 1;
        }
    }

}


template <typename T>
void _sort(T arr[], size_t n) {
    T *temp;
    try {
        temp = new T[n];
    } catch (std::bad_alloc& e) {
        abort();
    }
    merge_sort(arr, n, temp);
    //merge_sort_recursive(arr, 0, n-1, temp);
    delete [] temp;
}
