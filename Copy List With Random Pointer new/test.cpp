/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (!head) return nullptr;
        RandomListNode *nhead = getNewNode(head);
        RandomListNode *node = nhead;
        while (node) {
            node->next = getNewNode(head->next);
            node->random = getNewNode(head->random);
            node = node->next;
            head = head->next;
        }
        
        return nhead;
    }
    
    
    RandomListNode *getNewNode(RandomListNode *old) {
        if (!old) return nullptr;
        if (m.find(old) == m.end())
            m[old] = shared_ptr<RandomListNode>(new RandomListNode(old->label));
        return m[old].get();
    }
    
    map<RandomListNode *, shared_ptr<RandomListNode>> m;
};