#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size() < 3) return nums.size();
        int cnt = 1,
            last;
        last = nums[0];
        vector<int> to_remove;
        for (int i=1; i < nums.size(); i++) {
            if (nums[i] == last) {
                if (++cnt > 2)
                    to_remove.push_back(i);
			}
            else
                cnt = 1;
			//cout << last << " " << i << " " << nums[i] << " " << cnt << endl;
            last = nums[i];
			
        }
		
        for (auto riter=to_remove.rbegin(); riter != to_remove.rend(); riter++)
            nums.erase(nums.begin()+(*riter));
        return nums.size();
            
    }
};

int main () {
	vector<int> A = {-14,-14,-14,-14,-14,-14,-14,-13,-13,-13,-13,-12,-11,-11,-11,-9,-9,-9,-7,-7,-7,-6,-6,-5,-5,-5,-4,-4,-4,-3,-3,-3,-2,-2,-2,-1,-1,0,0,0,0,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,5,5,6,6,6,7,7,7,7,8,8,8,8,9,9,10,10,11,11,11,11,11,12,12,12,12,13,13,13,13,14,14,15,16,17,18,18,18,20,20,21,21,21,21,21,22,22,22,22,23,24,24,25};
	cout << Solution().removeDuplicates(A);
}
