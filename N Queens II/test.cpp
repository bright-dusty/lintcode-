#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n, int r=0, int cols=0, int diags=0, int trans=0) {
        // write your code here
        if (r == n)
            return 1;
        int cnt = 0;
        for (int c=0; c < n; c++) {
            int col = 1 << c;
            int diag = 1 << (r - c + n - 1);
            int tran = 1 << (r + c);
            if (!(col & cols) && !(diag & diags) && !(tran & trans))
                cnt += totalNQueens(n, r+1, col | cols, diag | diags, tran | trans);
        }
        return cnt;
    }
};

int main () {
    cout << Solution().totalNQueens(15);
}
