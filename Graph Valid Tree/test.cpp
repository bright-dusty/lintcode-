#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <memory>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        map<int, vector<int>> map;
        for (auto &edge : edges) {
            int i = edge[0], j = edge[1];
            for (int k=0; k < 2; k++) {
                if (map.find(i) == map.end())
                    map[i] = vector<int>({j});
                else {
                    map[i].push_back(j);
                }
                swap(i, j);
            }
        }
        if (n < 2) return true;
        if (map.empty()) return false; // forest
        
        unique_ptr<int[]> visited(new int[n]());
        queue<int> que;
        que.push(map.begin()->first);
        int cnt = 0;
        while (!que.empty()) {
            auto k = que.front();
            que.pop();
            if (!visited[k]) {
                if (map.find(k) != map.end())
                    for (auto node : map[k]) {
                        map[node].erase(find(map[node].begin(), map[node].end(), k));
                        que.push(node);
                    }
                        
                cnt ++;
            } else { // graph
                return false;
            }
            visited[k] = 1;
        }

        if (cnt != n)
            return false; // forest
        
        return true; // tree
        
            
    }
    

};

int main () {
    vector<vector<int>> edges = 
#include "14.in"
;
    int n = 1386;
    cout << Solution().validTree(n, edges);
}
