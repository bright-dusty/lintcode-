#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    /*
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        if (A.empty())
            return -1;
        size_t i = search_pos(A);
        if (target >= A[0] && target <= A[i])
            return b_search(A, 0, i, target);
        if (i+1 < A.size())
            return b_search(A, i+1,  A.size()-1, target);
        return -1;
    }
	
	ssize_t b_search(vector<int> &A, ssize_t start, ssize_t end, int t) {
		ssize_t _end = end;
		while (start <= end) {
			ssize_t mid = (start + end) / 2;
			if (A[mid] >= t)
				end = mid - 1;
			else
				start = mid + 1;
		}
		if (start > _end)
			return -1;
		if (A[start] != t)
			return -1;
		return start;
	}

	size_t search_pos(vector<int> &A) {
		ssize_t start = 0;
		ssize_t end = A.size() - 1;
		while (start < end && A[start] >= A[end]) {
			ssize_t mid = (start + end) / 2,
					_end = end;

			if (A[mid] <= A[start])
				end = mid - 1;
			if (A[mid] > A[_end])
				start = mid + 1;
			//else
			//	assert(0);
		}

		if (start > end) 
			swap(start, end);
		
		if (start == 0 && end == A.size() - 1)
			return start;
		else if (start - 1 > 0 && A[start] < A[start-1])
			return start - 1;
		else if (end + 1 < A.size() && A[end] > A[end+1])
			return end;

		for (ssize_t i=0; i+1 < A.size(); i++)
			if (A[i+1] < A[i])
				return i;
		assert (0);
	}
};

int main() {
	vector<int> A = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	cout << Solution().search(A, -1);
}

