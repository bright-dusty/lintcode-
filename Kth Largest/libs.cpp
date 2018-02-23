#include <ctime>
#include <sys/time.h>
#include <cstdio>
#include "MergeSort.cpp"

extern "C" {
    
    double sort (int arr[], size_t n) {
        timeval t0, t1;
        gettimeofday(&t0, nullptr);
        if (n)_sort(arr, n);
        gettimeofday(&t1, nullptr);
        double span = (t1.tv_sec - t0.tv_sec) * 1000.0 + 
                      (t1.tv_usec - t0.tv_usec) / 1000.0 ;
        
        //printf("Method : %s\n", "MergeSort");
        //printf("Scale : %d\n", n);
        //printf("Cost : %.2f ms\n", span);
        return span;
    };
}
