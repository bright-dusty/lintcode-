#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
    int majorityNumber(vector<int> &nums, int k) {
        // write your code here
        typedef int count_type;
        unordered_map<int, count_type> candidates;
        
        for (int ele : nums) {
            if (candidates.find(ele) != candidates.end())
                candidates[ele] ++ ;
            else if (candidates.size() < k - 1)
                candidates[ele] = 1;
            else {
                vector<int> to_remove;
                for (auto &item : candidates)
                    if (-- item.second == 0)
                        to_remove.push_back(item.first);
                for (int key : to_remove)
                    candidates.erase(key);
            }
                
        }
        
        count_type max_cnt = -1;
        int major ;
        
        for (auto &item : candidates)
            item.second = 0;
        for (int ele : nums) {
            if (candidates.find(ele) != candidates.end())
                if (++ candidates[ele] >  max_cnt) {
                    max_cnt = candidates[ele];
                    major = ele;
                }
                    
        }
        
        return major;
        
    }
};

int main () {
    vector<int> nums = {3,1,2,3,2,3,3,4,4,4};
    cout << Solution().majorityNumber(nums, 3);
}
