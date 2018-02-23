template <typename T>
void _sort (T arr[], size_t n) {
	size_t gap = 0;
	while (gap <= n/3)
		gap = gap * 3 + 1;
	while (gap) {
		for (size_t i=gap; i < n; i++) {
			T tmp = arr[i];
			ssize_t j = i - gap;
			for (; j >= 0 && arr[j] > tmp; j-=gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = tmp;
		}
		gap = (gap - 1) / 3;
	}
}

