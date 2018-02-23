#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
      return isMatch(s.c_str(), p.c_str());
    }
    bool isMatch(const char *s, const char *p) {
        // write your code here
        assert ( s && p );
        if (*p == '\0') return *s == '\0';

        #define matched \
            ((*p == *s) || (*p == '.' && *s != '\0'))
        if (*(p+1) != '*') {
            if (*p == '*') return false;
            return matched && isMatch(s+1, p+1);
        }
        while (matched) {
            if (isMatch(s, p+2)) return true;
            s ++;
        }
        #undef matched
        return isMatch(s, p+2);
    }

};

int main(int argc, char const *argv[]) {

    string str("aaaaaaaaaaaaab"), pattern("a*a*a*a*a*a*a*a*a*a*c");
    cout << Solution().isMatch(str, pattern);
    return 0;
}
