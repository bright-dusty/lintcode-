#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        unique_ptr<int[]>dp (new int[m+1]());
        for (int item : A) {
            for (int j=m; j > 0; j--)
                if (j-item >= 0)
                    dp[j] = max(dp[j], dp[j-item]+item);
        }
        return dp[m];
    }
};


int main() {
    int cap = 12;
    vector<int> items = {2, 3, 5, 7, 1};
    cout << Solution().backPack(cap, items);
}
