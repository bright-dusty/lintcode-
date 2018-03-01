#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<int>> cache;
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        vector<vector<int>> cache(A.length()+1);
        for (auto &item : cache)
            item.resize(B.length()+1, -1);
        this->cache.swap(cache);
        return lcs(A, B, A.length(), B.length());
    }
    
    int lcs(string &A, string &B, int i, int j) {
        if (!i || !j) return 0;
        if (cache[i][j] != -1)
            return cache[i][j];
        if (A[i-1] == B[j-1])
            cache[i][j] = lcs(A, B, i-1, j-1) + 1;
        else
            cache[i][j] = max(lcs(A, B, i, j-1), lcs(A, B, i-1, j));
        return cache[i][j];
    }
};

int main () {
    string A("CABEDD"), B("ABCDED");
    cout << Solution().longestCommonSubsequence(A, B);
}

