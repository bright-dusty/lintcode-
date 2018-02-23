#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    /*
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        map<multiset<char>, int> m;
        vector<string> anagrams;
        
        for (auto &str : strs) {
            auto chrset = to_set(str);
            if (m.find(chrset) != m.end())
                m[chrset] ++;
            else m[chrset] = 0;
        }
        for (auto &str : strs) {
            auto chrset = to_set(str);
            if (m[chrset])
                anagrams.push_back(str);
        }
        return anagrams;
            
    }
    
    template<class T>
    multiset<typename T::value_type> to_set (const T &s) {
        multiset<typename T::value_type> set;
        copy(s.begin(), s.end(), inserter(set, set.end()));
        return set;
    }
};

int main() {
	vector<string> strs = 
#include "10.in"
	;
	for (string &str : Solution().anagrams(strs))
		cout << str << endl;
}

