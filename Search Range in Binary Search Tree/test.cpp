/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    void dfs(queue<int> &vals, TreeNode *node) {
        if (!node)
            return;
        dfs(vals, node->left);
        vals.push(node->val);
        dfs(vals, node->right);
        
    }
    
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        queue<int> vals;
        vector<int> output = new vector<int>;
        dfs(vals, root);
        while (!vals.empty()) {
            if (k1 <= vals.front() && vals.front() <= k2)
                output.push_back(vals.front());
            vals.pop();
        }
        return output;
    }
};