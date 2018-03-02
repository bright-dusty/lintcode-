#include <cstdlib>
#include "swap.hpp"

template <typename T>
void _sort (T arr[], size_t n) {
    for (size_t i=0; i < n-1; i++)
        for (size_t j=0; j < n-1-i; j++)
            if (arr[j] > arr[j+1])
                swap<T>(arr[j], arr[j+1]);
}

