#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <iostream>

#include <assert.h>

using namespace std;

class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        typedef int level_t;
        typedef pair<string, level_t> que_t;
        
        queue<que_t> que ;
        dict.erase(start);
		dict.insert(end);
        que.push(que_t(start, 1));
        
        auto nearest = [] (const string& a, const string& b) {
            assert(a.length() == b.length());
            size_t dis = 0;
            for (ssize_t i=0; i < a.length(); i++)
                if (a[i] != b[i])
                    dis ++;
            return dis == 1;
        };
        
        while (!que.empty()) {
            vector<string> to_remove;
            que_t ele = que.front();
            que.pop();
            
            if (ele.first == end)
                return ele.second;
            
            for (auto &s : dict) {
                if (nearest(s, ele.first)) {
                    que.push(que_t(s, ele.second+1));
                    to_remove.push_back(s);
                }
            }
                
            for (auto &s : to_remove)
                dict.erase(s);
   
        }
        
        return 0;
        
    }
    
};

int main() {
	vector<string> dt = {"hot","dot","dog","lot","log"};
	unordered_set<string> dict;

	copy(dt.begin(), dt.end(), inserter(dict, dict.end()));
	string s("hit"), e("cog");
	
	cout << Solution().ladderLength(s, e, dict);
}
