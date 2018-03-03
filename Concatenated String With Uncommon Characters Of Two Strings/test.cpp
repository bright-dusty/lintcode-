#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include <memory.h>

using namespace std;

class Solution {
public:
    static void prepare(int map[256], string &s) {
        for (size_t i=0; i < s.length(); i++)
            map[s[i]] = i;
    }
    /*
     * @param : the 1st string
     * @param : the 2nd string
     * @return: uncommon characters of given strings
     */
    static string concatenetedString(string &s1, string &s2) {
        // write your code here
        int  tmp1[256], tmp2[256];
        
        fill_n(tmp1, 256, -1);
        fill_n(tmp2, 256, -1);
        prepare(tmp1, s1);
        prepare(tmp2, s2);
        
        ostringstream streambuf;
        #define concat(s) \
        for (size_t i=0; i < s.length(); i++) \
            if (!(tmp1[s[i]] != -1 && tmp2[s[i]] != -1)) \
                streambuf << s[i];
    
        concat(s1);
        concat(s2);
        #undef concat
        return streambuf.str();
    }
};


int main() {
    string s1("abcs"),
           s2("cxzca");
    cout << Solution::concatenetedString(s1, s2);
}
