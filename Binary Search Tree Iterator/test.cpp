#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
  public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
  };
  
class Solution {
public:
    static string serialize(TreeNode *);
    static TreeNode * deserialize(string &);     
    static void destroy (TreeNode *);
};

class BSTIterator {
private:
    vector<TreeNode *> path;
public:

    void partial_visit(TreeNode *node) {
        if (!node) return;
        
        do {
            path.push_back(node);
        } while (node=node->left);
    }
    
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        partial_visit(root);
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        //while (!path.empty() && !path.back())
        //    path.pop_back();
        return !path.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        TreeNode *node = path.back();
        node = path.back();
        path.pop_back();
        if (node->right)
            partial_visit(node->right);
        return node;
    }
};


int main()  {
    string line;
    
    getline(cin, line);
    TreeNode *root = Solution::deserialize(line);
    auto iter = BSTIterator(root);
    while (iter.hasNext()) {
        cout << iter.next()->val << endl;
    }
    Solution::destroy(root);
}
