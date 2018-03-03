#include <iostream>
#include <vector>
#include <set>
#include <assert.h>

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
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    
    bool dfs(vector<TreeNode *> &vals, TreeNode *node, TreeNode *target) {
        vals.push_back(node);
        if (!node) {
            return false;
        } else if (node == target) 
            return true;
        

        
        if (dfs(vals, node->left, target))
            return true;
        vals.pop_back();
        if (dfs(vals, node->right, target))
            return true;
        vals.pop_back();
        return false;
    }
    
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        vector<TreeNode *> ancestors_A, ancestors_B;
        assert (dfs(ancestors_A, root, A));
        assert (dfs(ancestors_B, root, B));
        set<TreeNode *> ancestors_A_set ;
        for (auto iter=ancestors_A.begin(); iter != ancestors_A.end(); iter++)
            ancestors_A_set.insert(*iter);
        for (auto iter=ancestors_B.rbegin(); iter != ancestors_B.rend(); iter++)
            if (ancestors_A_set.find(*iter) != ancestors_A_set.end())
                return *iter;

        assert (0);
    }
};

int main () {
    TreeNode n1(4);
    TreeNode n2(3);
    TreeNode n3(7);
    TreeNode n4(5);
    TreeNode n5(6);
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;
    
    cout << Solution().lowestCommonAncestor(&n1, &n2, &n4)->val;
}
