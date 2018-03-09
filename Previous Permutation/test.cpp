#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return nums;
        
        auto i = nums.end();
        decltype(i)    j, k;
        for (--i; i != nums.begin();) {
            j = i -- ;
            if (!(*i > *j)) continue;
            for (k=nums.end(); !(*i > *(--k)););
            iter_swap(i, k);
            reverse(j, nums.end());
            return nums;
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};

int main () {
    vector<int> arr = {2, 3, 3, 1};
    Solution().previousPermuation(arr);
    for (int ele : arr)
        cout << ele << " ";
}
