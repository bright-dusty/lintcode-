#include <vector>
#include <algorithm>
#include <iostream>

#include <limits.h>

using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        vector<pair<int, int>> sums;
        int sum = 0;
        for (size_t i=0; i < nums.size(); i++)
            sums.push_back(make_pair(sum=sum+nums[i], i));
        sort(sums.begin(), sums.end());
        vector<int> subarray = {0, 0};
        int diff = INT_MAX;
        for (ssize_t i=0; i < static_cast<ssize_t>(sums.size())-1; i++) {
            if (sums[i+1].first - sums[i].first < diff) {
                diff = sums[i+1].first - sums[i].first;
                int left = sums[i].second, right = sums[i+1].second;
                if (left > right)
                    swap(left, right);
                subarray = {left+1, right};
            }
        }
        return subarray;
    }
};

int main () {
    vector<int> arr = {-3, 1, 1, -3, 3}; // (-4, 3) (-3, 0) (-2, 1) (-1, 2) (-1, 4)
    for (int index : Solution().subarraySumClosest(arr))
        cout << index << " ";
}s
