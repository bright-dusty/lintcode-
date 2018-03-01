#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if (strs.empty()) return string("");
        ostringstream strout;
        int i = 0;
        while (true) {
            for (auto &str : strs) {
                if (i >= str.length() || str[i] != strs[0][i])
                    goto Exit;
            }
            strout << strs[0][i++];
        }
        Exit:
        return strout.str();
    }
};

int main () {
    vector<string> strs = {"ABC", "AB", "ABD"};
    cout << Solution().longestCommonPrefix(strs);
}
