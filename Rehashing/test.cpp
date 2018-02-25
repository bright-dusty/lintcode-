#include <vector>
#include <iostream>

using namespace std;

class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
 };

class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        vector<ListNode*> nodes;
        ssize_t size = hashTable.size() * 2;
        for (auto &node: hashTable) {
            while (node) {
                nodes.push_back(node);
                node = node->next;
            }
            
        }
        vector<ListNode*> _new(size, nullptr);
        for (auto &node: nodes) {
            int index = (node->val % size + size) % size;
            if (_new[index]) {
                auto tail = _new[index];
                while (tail->next)
                    tail = tail->next;
                tail->next = node;
            } else {
                _new[index] = node;
            }
            node->next = nullptr;
                
        }
        return _new;
        
    }
};


int main() {
    vector<ListNode*> nodes (5, nullptr);
    ListNode n1(42), n2(32), n3(-7);
    nodes[2] = &n1;n1.next = &n2;
    nodes[3] = &n3;
    for (auto node: Solution().rehashing(nodes)) {
        while (node) {
            cout << node->val << "->";
            node = node->next;
        }
        cout << "null" << " ";
    }
}
