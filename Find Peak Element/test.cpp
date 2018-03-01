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
            if (s >= e) return 0;
            int m = (s + e) / 2;
    
            if (A[m-1] < A[m] && A[m+1] < A[m])
                return m;
			if (A[m] < A[m+1])
				return peak(m+1, e);
			else
				return peak(s, m);
            
        };
        
        return peak(0, A.size()-1);
    }
};

int main() { 
    vector<int> A = 
	{1,2,1,3,4,5,7,6}
;
    cout << Solution().findPeak(A);
}
