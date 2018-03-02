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
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int j = -1;
        int p = -1;
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] < k)
                swap(nums[++j], nums[i]);
			if (nums[i] == k)
                p = i;
        }
        if (p != -1)
            swap(nums[j+1], nums[p]);
        return j + 1;
    }
};

int main() {
    vector<int> nums = {12,15,1,18,2,35,30,11};
    cout << Solution().partitionArray(nums, 15) << endl;
    for (int n : nums)
        cout << n << " ";
    cout << endl;
}
