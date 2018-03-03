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
    /*
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode * head) {
        // write your code here
        if (!(head && head->next))
            return false;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
