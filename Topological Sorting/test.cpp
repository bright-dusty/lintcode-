#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

typedef struct DirectedGraphNode {
    int label;
     vector<DirectedGraphNode *> neighbors;
     DirectedGraphNode(int x) : label(x) {};
 } node_t, *node_p;


class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        vector<DirectedGraphNode*> sorted;
        map<DirectedGraphNode*, int> indegree;
        
        for (auto node : graph) {
            if (indegree.find(node) == indegree.end())
                indegree[node] = 0;
            for (auto next : node->neighbors) {
                if (next == node)
                    continue;
                if (indegree.find(next) == indegree.end()) 
                    indegree[next] = 1; 
                else 
                    indegree[next] ++;
            }
        }
        
        queue<DirectedGraphNode*> que;
        for (auto &item : indegree) {
            if (!item.second)
                que.push(item.first);
        }
        
        while (!que.empty()) {
            auto node = que.front();
            que.pop();
            sorted.push_back(node);
            for (auto next : node->neighbors) {
                indegree[next] --;
                if (!indegree[next])
                    que.push(next);
            }
                
                 
                    
            
        }
        
        return sorted;
            
        
    }
};

int main() {
    node_t n0(0), n1(1), n2(2), n3(3), n4(4);
    n4.neighbors = vector<node_p>({&n1, &n2, &n3, &n4});
    vector<node_p> graph = {&n0, &n1, &n2, &n3, &n4};
    for (auto node : Solution().topSort(graph))
        cout << node->label << " ";
}
