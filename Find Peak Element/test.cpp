#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int>& A) {
        // write your code here
        function<int(int, int)> peak = [&](int s, int e) -> int
        {
            if (s >= e-1) return 0;
            int m = (s + e) / 2;
            //if (m-1 > 0 && m+1 < A.size())
    
            if (A[m-1] < A[m] && A[m+1] < A[m])
                return m;
            int r = peak(m, e);
            if (r) return r;
            int l = peak(s, m);
            if (l) return l;
            
        };
        
        return peak(0, A.size()-1);
    }
};

int main() { 
    vector<int> A = 
#include "13.in"
;
    cout << Solution().findPeak(A);
}
