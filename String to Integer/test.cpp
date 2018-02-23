#include <string>
#include <iostream>
#include <sstream>
#include <limits.h>
#include <assert.h>

using namespace std;

class Solution {
public:
    /*
     * @param str: A string
     * @return: An integer
     */
    
    static bool isdigit(const char c) {
        if (c-'0' >= 0 && c-'0' < 10)
            return true;
        return false;
    }
    
    static int times10(int &num) {
        int overflow;
        __asm__(
            "movl %2, %%eax\n\t"
            "imull $10, %%eax\n\t"
            "movl $0, %1\n\t"
            "jno 1f\n\t"
            "movl $1, %1\n\t"
            "1:movl %%eax, %0\n\t"
            :"=r"(num), "=r"(overflow)
            :"r"(num)
            :"%eax", "%edx"
        );
        return overflow;
    }
    
    static int add(int &num, int inc) {
        int overflow ;
        __asm__(
            "movl %2, %%eax\n\t"
            "addl %3, %%eax\n\t"
            "movl $0, %1\n\t"
            "jno 1f\n\t"
            "movl $1, %1\n\t"
            "1:movl %%eax, %0\n\t"
            :"=r"(num), "=r"(overflow)
            :"r"(num), "r"(inc)
            :"%eax"
        );
        return overflow ;
    }
    
    static int atoi(string &str) {
        // write your code here
        if (str.empty())
            return 0;
        
        const char * data = str.data();
        size_t i = 0;
        int sign = 1;
        int num = 0;
        
        while (i < str.length() && data[i] == ' ')
            i++;
        if (i == str.length())
            return 0;
        
        if (data[i] == '-' || data[i] == '+') {
            sign = data[i++] == '+' ? 1 : -1;
            
        } else if (!isdigit(data[i]))
            return 0;
        
        for (; i < str.length(); i++) {
            if (!isdigit(data[i]))
                break;
            else {
                if (times10(num) ||
                    add(num, sign * (data[i]-'0'))) 
                    if (sign == 1)
                        return INT_MAX;
                    else if (sign == -1)
                        return INT_MIN;
            }
        }
        return num;
    }
};


int main() {
    string digit ;cin >> digit;
    stringstream s(digit);
    int val;
    s >> val;
    assert (Solution::atoi(digit) == val);
}
