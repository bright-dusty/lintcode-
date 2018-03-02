#include <cstdlib>

template <typename T>
void _sort (T arr[], size_t n) {
    for (size_t i=1; i < n; i++) {
        ssize_t left_bound = 0;
        ssize_t right_bound = i-1;
        while (left_bound <= right_bound) {
            size_t mid = (left_bound + right_bound) / 2;
            if (arr[mid] > arr[i])
                right_bound = mid - 1;
            else
                left_bound = mid + 1;
        }
        T tmp = arr[i];
        for (ssize_t j=i-1; j >= left_bound; j--)
            arr[j+1] = arr[j];
        arr[left_bound] = tmp;
    }
}

