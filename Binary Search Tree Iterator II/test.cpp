#include <iostream>
#include <vector>
#include <stack>
#include <memory>

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
      static void preorder_dfs (vector<TreeNode *> &vec, TreeNode *node) {
          if (!node) return;
          
          vec.push_back(node);
          preorder_dfs(vec, node->left);
          preorder_dfs(vec, node->right);
      }
      static void inorder_dfs(vector<TreeNode *> &vec, TreeNode *node) {
          if (!node) return;
          
          inorder_dfs(vec, node->left);
          vec.push_back(node);
          inorder_dfs(vec, node->right);
      }
      static void postorder_dfs(vector<TreeNode *> &vec, TreeNode *node) {
          if (!node) return;
          
          postorder_dfs(vec, node->left);
          postorder_dfs(vec, node->right);
          vec.push_back(node);
      }
      
  };
  
class Solution {
public:
    static string serialize(TreeNode *);
    static TreeNode * deserialize(string &);     
    static void destroy (TreeNode *);
};

class BSTIterator {
public:
    virtual bool hasNext() = 0;
    virtual TreeNode *next() = 0;
};

class InorderBSTIterator : public BSTIterator {
private:
    stack<TreeNode *> path;
    void partial_visit(TreeNode *node) {
        if (!node) return;
        
        do {
            path.push(node);
        } while (node=node->left);
    }
public:
    InorderBSTIterator(TreeNode * root) {
        partial_visit(root);
    }

    bool hasNext() {
        return !path.empty();
    }

    TreeNode * next() {
        TreeNode *node = path.top();
        path.pop();
        partial_visit(node->right);
        return node;
    }
};

class PreorderBSTIterator : public BSTIterator {
private:
    stack<TreeNode *> path;
public:
    PreorderBSTIterator (TreeNode * root) {
        if (root)
            path.push(root);
    }
    bool hasNext() {
        return !path.empty();
    }
    TreeNode * next() {
        TreeNode *node = path.top();
        path.pop();
        if (node->right)
            path.push(node->right);
        if (node->left)
            path.push(node->left);
        return node;
    }
};

class PostorderBSTIterator : public BSTIterator {
private:
    stack<pair<TreeNode *, int>> path;
public:
    PostorderBSTIterator (TreeNode * root) {
        if (root)
            path.push({root, 0});
    }
    bool hasNext() {
        return !path.empty();
    }
    TreeNode * next() {
        for (;;) {
            auto &node = path.top();
            if (node.second) {
                path.pop();
                return node.first;
            } else {
                node.second ++ ;
                if (node.first->right)
                    path.push({node.first->right, 0});
                if (node.first->left)
                    path.push({node.first->left, 0});
            } 
        }
    }
};


int main()  {
    string line;
    
    getline(cin, line);
    TreeNode *root = Solution::deserialize(line);
    
    typedef unique_ptr<BSTIterator> iter_type;
    iter_type
    inorder_iter = iter_type(new InorderBSTIterator(root)),
    preorder_iter = iter_type(new PreorderBSTIterator(root)),
    postorder_iter = iter_type(new PostorderBSTIterator(root)) ;
    
    vector<TreeNode *> inorder, preorder, postorder; 
    TreeNode::inorder_dfs(inorder, root);
    TreeNode::preorder_dfs(preorder, root);
    TreeNode::postorder_dfs(postorder, root);
    
    auto in_ele = inorder.begin();
    auto pre_ele = preorder.begin();
    auto post_ele = postorder.begin();
    
    while (inorder_iter->hasNext()) {
        auto node = inorder_iter->next();
        assert (*(in_ele++) == node);
        cout << node->val << endl;
    }
    
    while (preorder_iter->hasNext()) {
        auto node = preorder_iter->next();
        assert (*(pre_ele++) == node);
        cout << node->val << endl;
    }
    
    while (postorder_iter->hasNext()) {
        auto node = postorder_iter->next();
        assert (*(post_ele++) == node);
        cout << node->val << endl;
    }

    Solution::destroy(root);
}
