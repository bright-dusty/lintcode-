#include <vector>
#include <map>
#include <queue>
#include <algorithm>
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
		if (forest(n, map)) return false;
		auto has_one_neighbor = [&]() {
			for (auto &kv : map)
				if (kv.second.size() <= 1)
					return kv.first;
			return -1;
		};
		int k;
		while ((k=has_one_neighbor()) != -1) {
			for (int j : map[k])
				map[j].erase(find(map[j].begin(), map[j].end(), k));
			map.erase(k);
		}
		
		
		return map.empty();
			
			
    }
	bool forest(int n, map<int, vector<int>> &map) {
		if (n < 2) return false;
		if (map.empty()) return true;
		int *visited = new int[n]();
		queue<int> que;
		que.push(map.begin()->first);
		int cnt = 0;
		while (!que.empty()) {
			auto k = que.front();
			que.pop();
			if (!visited[k]) {
				if (map.find(k) != map.end())
					for (auto node : map[k])
						que.push(node);
				cnt ++;
			}
			visited[k] = 1;
		}
		
		delete [] visited;
		return cnt != n;
	}

};

int main () {
	vector<vector<int>> edges = 
#include "14.in"
;
	int n = 1386;
	cout << Solution().validTree(n, edges);
}
