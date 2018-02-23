#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    /*
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    static bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
		ssize_t start = 0;
		ssize_t end = 0;
		if (!matrix.size())
			return false;
		end = matrix.size() * matrix[0].size() - 1;
		#define access(x) \
		ssize_t r = x / matrix[0].size(); \
		ssize_t c = x % matrix[0].size(); 
		

		while (start <= end) {
			ssize_t mid = (start + end) / 2;
			access(mid);
			if (matrix[r][c] >= target)
				end = mid - 1;
			else
				start = mid + 1;
		}
		access(start);
		if (start < matrix.size() * matrix[0].size() && matrix[r][c] == target)
			return true;
		return false;
    }
};

int main() {
	vector<vector<int>> m = {{1, 3, 5, 7},
							 {10, 11, 16, 20},
							 {23, 30, 34, 50}};
	
    cout << Solution::searchMatrix(m, 60);

}
