#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k, int s, int e) {
        // write your code here
        int j = s-1;
        int p = e;//-1;
        for (int i=s; i < e; i++) {
            if (nums[i] < k)
                swap(nums[++j], nums[i]);
            //else if (nums[i] == k && p == -1)
             //   p = i;
        }
        //if (p != -1)
            swap(nums[j+1], nums[p]);
        return j + 1;
    }
    
    void sort(vector<int> &arr, int s, int e) {
        if (s >= e) return;
        
        int p = partitionArray(arr, arr[e], s, e);
        
        sort(arr, s, p-1);
        sort(arr, p+1, e);
    }
};

int main() {
    vector<int> arr = {9,9,9,8,9,8,7,9,8,8,8,9,8,9,8,8,6,9};
    Solution().sort(arr, 0, arr.size()-1) ;
    for (int x : arr)
        cout << x << " " ;
}
