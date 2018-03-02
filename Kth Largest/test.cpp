#include <vector>
#include <iostream>

using namespace std;

ssize_t partition(vector<int> &arr, ssize_t s, ssize_t e) {
    int &pivot = arr[s];
    ssize_t j = s ;
    for (ssize_t i=s+1; i <= e; i++)
        if (arr[i] >= pivot)
            swap(arr[++j], arr[i]);
    swap(pivot, arr[j]);
    return j;
}

/*
ssize_t partition_yan_ver(vector<int> &arr, ssize_t s, ssize_t e) {
    int pivot = arr[s];
    while (s < e) {
        while (s < e && arr[e] >= pivot) -- e;
        arr[s] = arr[e];
        while (s < e && arr[s] <= pivot) ++ s;
        arr[e] = arr[s];
    }
    arr[s] = pivot;
    return s;
}*/

class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        ssize_t s = 0, e = nums.size() - 1;
        while (true) {
            ssize_t i = partition(nums, s, e);
            if (i == n - 1)
                return nums[i];
            else if (i > n - 1)
                e = i - 1;
            else s = i + 1;
        }
    }
};


int main () {
    vector<int> arr = {12,15,1,18,2,35,30,11};
    /*vector<int> arr2 = arr;
    
    cout << partition(arr, 0, arr.size()-1) << endl;
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
    
    cout << partition_yan_ver(arr2, 0, arr2.size()-1) << endl;
    for (int ele : arr2)
        cout << ele << " ";
    cout << endl;*/
    
    cout << Solution().kthLargestElement(2, arr);
    
}
