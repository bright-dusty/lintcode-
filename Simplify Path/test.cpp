#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

#define Jump(label) asm volatile ("jmp "#label:::)
#define Label(name) asm volatile (#name":":::)

vector<string> split(string &data, char sep=' ') {
    vector<string> slices;
    
    if (data.empty()) Jump(Ret);
    
    size_t s=0, e;
    e = data.find(sep, s);

    while (e != string::npos) {
        slices.push_back(data.substr(s, e-s));

        s = e + 1;
        e = data.find(sep, s);
    }

    string tail = data.substr(s, data.length()-s);
    if (!tail.empty()) slices.push_back(tail);

    Label(Ret);return slices;

}

class Solution {
public:
    /**
     * @param path: the original path
     * @return: the simplified path
     */
    string simplifyPath(string &path) {
        // write your code here
        auto slices = split(path, '/');
        vector<string> segments;
        
        for (auto &str : slices)
            if (str != ".") {
                if (str == "..") {
                    if (!segments.empty() && segments.back() != "/")
                        segments.pop_back();
                } else if (!str.empty())
                    segments.push_back(str);
            }
        if (segments.empty())
            return "/";
        
        ostringstream strout;
        for (auto &str : segments)
            strout << "/" << str;
        return strout.str();
    }
};

int main () {
    string data = "/../";
    
    cout <<  Solution().simplifyPath(data);

}

