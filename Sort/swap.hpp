template <typename T> inline
void swap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

template <typename T> inline
void swap(T arr[], size_t a, size_t b) {
    T c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}
