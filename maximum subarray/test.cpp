#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        if (nums.empty())
            return 0;
        
         
        int sum = 0;
        int max = INT_MIN;
 
        for (int i = nums.size()-1; i >= 0; i--) 
        {
            // choose a larger one between current number or (previous sum + current number).
            if (sum <= 0)
				sum = nums[i];
			else
				sum += nums[i];
            max = std::max(max, sum);    // choose the larger max.
        }
 
	return max;}
};


int main () {
	vector <int> nums = {-2,2,-3,4,-1,2,1,-5,3};
	cout << Solution().maxSubArray(nums);
}
