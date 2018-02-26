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
            else if (nums[i] == k && p == -1)
                p = i;
        }
        if (p != -1)
            swap(nums[j+1], nums[p]);
        return j + 1;
    }
};

int main() {
    vector<int> nums = {2, 3, 4, 1, 4, 6, 8};
    cout << Solution().partitionArray(nums, 8) << endl;
    for (int n : nums)
        cout << n << " ";
    cout << endl;
}
