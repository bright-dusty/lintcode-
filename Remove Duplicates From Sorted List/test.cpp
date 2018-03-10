#include <iostream>

using namespace std;

class ListNode {
 public:
     int val;
     ListNode* next;
     ListNode (int val) {
        this->val = val;
        this->next = NULL;
     }
 };


class Solution {
public:
    /**
     *@param head: head is the head of the linked list
     *@return: head of linked list
    **/
    ListNode* deleteDuplicates(ListNode* head) {
        // write your code here
        if (!head) return nullptr;
        ListNode *l=head, *c=head;
        while (c->next) {
            c = c->next;
            if (c->val == l->val) {
                l->next = c->next;  
            } else {
                l = c;
            }
        }
        return head;
    }
};

int main () {
    ListNode n0(0), n1(0), n2(0), n3(1), n4(1), n5(2), n6(3), n7(3);
    #define link(p, n) p.next = &n;
    link(n0, n1);
    link(n1, n2);
    link(n2, n3);
    link(n3, n4);
    link(n4, n5);
    link(n5, n6);
    link(n6, n7);
    
    ListNode* n = Solution().deleteDuplicates(&n0);
    while (n) {
        cout << n->val << " "; 
        n = n->next;
    }
}
