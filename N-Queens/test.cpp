#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> range(int n) {
	vector<int> range(n);
	for (int i=0; i < n; i++)
		range[i] = i;
	return range;
}


class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
		auto rows = range(n);
		vector<vector<string>> solutions;
		do {
			set<int> plus, sub;
			vector<string> solution;
			for (int r=0; r < n; r++) {
				if (plus.find(rows[r]+r) != plus.end() || sub.find(rows[r]-r) != sub.end())
					goto Continue;
				plus.insert(rows[r] + r);
				sub.insert(rows[r] - r);
			}
			for (int r=0; r < n; r++) {
				string row(n, '.');
				row[rows[r]] = 'Q';
				solution.push_back(row);
			}
			solutions.push_back(solution);
			Continue:;
				
		} while (next_permutation(rows.begin(), rows.end()));
		return solutions;
    }
};



int main () {
	cout << Solution().solveNQueens(9).size();
}

