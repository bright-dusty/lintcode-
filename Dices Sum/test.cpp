#include <vector>
#include <iostream>

#include <assert.h>

using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        assert (n);
        auto sums = dices_throw_once();
        for (int i=2; i <= n; i++) {
            vector<pair<int, double>> sum ;
            for (int j=1; j <= 6*i; j++) {
                sum.push_back({j, 0});    
            }
            for (auto &item1 : sums.back())
                for (auto &item2 : sums[0])
                    sum[item1.first+item2.first-1].second += item1.second * item2.second;
            sums.push_back(sum);
                
        }

        vector<pair<int, double>> ret ;
        copy(sums[n-1].begin()+(n-1), sums[n-1].end(), back_inserter(ret));
        return ret;
    }
    
    vector<vector<pair<int, double>>> dices_throw_once() {
        vector<vector<pair<int, double>>> sums = {{}};
        for (int i=1; i <= 6; i++)
            sums[0].push_back({i, 1./6});
        return sums;
    }
};

int main () {
    auto sum = Solution().dicesSum(3);
    double total = 0;
    for (auto &item : sum) {

        cout << item.first << ":" << item.second << " ";
    }

}
