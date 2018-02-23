#include <cstdlib>
#include "swap.hpp"

template <typename T>
void _sort (T arr[], size_t n) {
	for (size_t i=0; i < n; i++) {
		size_t min_index = i;
		for (size_t j=i+1; j < n; j++)
			if (arr[min_index] > arr[j])
				min_index = j;
		if (min_index != i)
			swap<T>(arr[min_index], arr[i]);
	}	
}
