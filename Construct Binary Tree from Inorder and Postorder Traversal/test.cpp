#include <map>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <iostream>

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
private:
    map<int, shared_ptr<TreeNode>> ptrmgr;
    TreeNode* buildNode(int val) {
        if (ptrmgr.find(val) == ptrmgr.end())
            ptrmgr[val] = shared_ptr<TreeNode>(new TreeNode(val));
        return ptrmgr[val].get();
    }
    
public:
    static string serialize(TreeNode *);

    /*
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int> &inorder, int il, int ir, vector<int> &postorder, int pl, int pr) {
        if (il > ir || pl > pr) return nullptr;
        TreeNode* root = buildNode(postorder[pr]);
        int i = find(inorder.begin()+il, inorder.end(), root->val) - inorder.begin();
        
        root->left = buildTree(inorder, il, i-1, postorder, pl, pl+i-il-1);
        root->right = buildTree(inorder, i+1, ir, postorder, pl+i-il, pr-1);
        return root;
    }
    
};

int main () {
    vector<int> inorder = {1, 2, 3};
    vector<int> postorder = {3, 2, 1};
    
    Solution solv;
    auto root = solv.buildTree(inorder, postorder);
    cout << solv.serialize(root);
}
