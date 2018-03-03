

class Solution {
private:
    vector<vector<int>> cache;

    
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        vector<vector<int>> cache(A.length()+1);
        for (auto &item : cache)
            item.resize(B.length()+1, -1);
        this->cache.swap(cache);
        int max_len = 0;
        for (int i=A.length(); i >= 0; i--)
            for (int j=B.length(); j >= 0; j--)
                max_len = max(lcs(A, B, i, j), max_len);
        return max_len;
    }
    
    int lcs(string &A, string &B, int i, int j) {
        if (!i || !j) return 0;
        if (cache[i][j] != -1)
            return cache[i][j];
        if (A[i-1] == B[j-1])
            cache[i][j] = lcs(A, B, i-1, j-1) + 1;
        else
            cache[i][j] = 0;
        return cache[i][j];
    }
};


