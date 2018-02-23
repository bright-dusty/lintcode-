#include <string>
#include <iostream>
#include <memory.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    /*
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
	size_t prepare(int map[256], string &s) {
		size_t cnt = 0;
		for (size_t i=0; i < s.length(); i++) {
			if (!map[s[i]])
				cnt ++;
			map[s[i]] ++;
		}
		return cnt;
			
	}
	
    string minWindow(string &source, string &target) {
        // write your code here
		int contains[256],
			map[256];
		memset(contains, 0, sizeof(contains));
		memset(map, 0, sizeof(map));
		size_t t_len = prepare(contains, target);
		
		string &s = source;
		size_t cnt = 0,
			   start = 0,
			   end = 0,
			   min_len = INT_MAX,
			   min_start = 0;
		for (; end < s.length(); end++) {
			if (contains[s[end]]) {
				map[s[end]] ++;
				if (map[s[end]] == contains[s[end]])
					cnt ++;
				while (cnt == t_len) {
					if (contains[s[start]]) {
						map[s[start]] --;
						if (map[s[start]] < contains[s[start]]) {
							if (end-start+1 < min_len) {
								min_len = end-start+1;
								min_start = start;
							}
							cnt --;
						}
							
					}
					start ++;
				}
			} 
		}
		if (min_len == INT_MAX)
			return string("");
		return s.substr(min_start, min_len);
	}
};

int main() {
	string src("aasaaaabcdd"),
		   target("abcdd");
	cout << Solution().minWindow(src, target);
}
