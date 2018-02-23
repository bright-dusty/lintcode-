#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) {
        // write your code here

        map<pair<ssize_t, ssize_t>, bool> matched_postions;
        vector<pair<ssize_t, ssize_t>> matched_postions_vec;
        
        auto dup = [&](ssize_t i, ssize_t j) {
            auto key = pair<ssize_t, ssize_t>(i, j);
            if (matched_postions.find(key) != matched_postions.end())
                return true;
            return false;
        };
        auto out_of_bound = [&](ssize_t i, ssize_t j) {
            if (i < 0 || i >= board.size())
                return true;
            if (j < 0 || j >= board[i].size())
                return true;
            return false;
        };
        
        for (ssize_t r=0; r < board.size(); r++) {
            for (ssize_t c=0; c < board[r].size(); c++) {
                if (board[r][c] == word[matched_postions_vec.size()]) {
                    auto key = pair<ssize_t, ssize_t>(r, c);
                    matched_postions_vec.push_back(key);
                    matched_postions[key] = true;
					vector<int> skip = {0};
                    while (!matched_postions_vec.empty()) {
                        if (matched_postions_vec.size() == word.length())
                            return true;
                        auto dim = matched_postions_vec.back();
                        vector<pair<ssize_t, ssize_t>> avail_pos = {
                            make_pair(dim.first-1, dim.second),
                            make_pair(dim.first+1, dim.second),
                            make_pair(dim.first, dim.second-1),
                            make_pair(dim.first, dim.second+1)
                        };
                        bool matched = false;
						int index = 0;
                        for (auto dim : avail_pos) {
                            ssize_t i = dim.first,
                                    j = dim.second;
							if (index ++ < skip.back())
								continue;
							skip[skip.size()-1] += 1;
                            if (out_of_bound(i, j) || dup(i, j) || board[i][j] != word[matched_postions_vec.size()]) { }
                            else  {
                                matched = true;
								skip.push_back(0);
                                matched_postions_vec.push_back(dim);
                                matched_postions[dim] = true;
								break;
                            }
                        }
                        if (!matched) {
                            skip.pop_back();
                            matched_postions.erase(matched_postions_vec.back());
							matched_postions_vec.pop_back();
                        }
                        
                            
                    }
                    
                } 
                    
            }
            
        }
    
		return false;
	}
};

int main() {
	vector <vector<char>> board = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};
	string s("ABCESEEDASA");
	cout << Solution().exist(board, s);
}
