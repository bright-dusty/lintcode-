#include <vector>
#include <queue>
#include <memory>
#include <string>
#include <sstream>
#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

using namespace std;

class Solution {
public:
    static string serialize(TreeNode *);
    static TreeNode * deserialize(string &); 
    static void destroy (TreeNode *);
};

string Solution::serialize(TreeNode * root) {
    // write your code here
    std::vector<TreeNode *> nodes;
    std::vector<std::string> output;
    
    ostringstream strout;
    nodes.push_back(root);
    while (nodes.size()) {
        TreeNode *node = nodes.front();nodes.erase(nodes.begin());
        if (node) {
            output.push_back(std::to_string(node->val));
            nodes.push_back(node->left);
            nodes.push_back(node->right);
        } else {
            output.push_back("#");
        }
                
    }
    while (output.size() && output.back() == "#")
        output.pop_back();
    strout << "{";
    for (ssize_t i=0; i < static_cast<ssize_t>(output.size())-1; i++) {
        strout << output[i];
        strout << ",";
    }
    if (output.size())
        strout << output[output.size()-1];
    strout << "}";
    return strout.str();
}

TreeNode * Solution::deserialize(string &data) {
    if (data.length() < 3) return nullptr;
    std::vector<std::string> slices;
    char comma = ',';
    size_t pos1 = 1, pos2;
    pos2 = data.find(comma, pos1);
    while (std::string::npos != pos2) {
        slices.push_back(data.substr(pos1, pos2-pos1));

        pos1 = pos2 + 1;
        pos2 = data.find(comma, pos1);
    }
    string tmp = data.substr(pos1, data.length()-1-pos1);
    if(!tmp.empty()) slices.push_back(tmp);
    
    if (!slices.size())
        return nullptr;
    
    size_t cur = 0;
    stringstream stream(slices[cur]);
    TreeNode *node = new TreeNode(0);
    stream >> node->val ;
    std::queue<TreeNode *> back;
    back.push(node);
    TreeNode *root = node;
    while (back.size() && cur < slices.size()) {
        node = back.front();back.pop();
        size_t l = ++cur;
        size_t r = ++cur;
        #define link_node(x, pos) \
        if (x < slices.size() && slices[x] != "#") { \
            TreeNode *child = new TreeNode(0); \
            stringstream stream(slices[x]); \
            stream >> child->val; \
            node->pos = child; \
            back.push(child); \
        }
            
        link_node(l, left);
        link_node(r, right)
        #undef link_node

    } 
        
    return root;
}
    
void Solution::destroy (TreeNode * root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}
/*
int main() {
    TreeNode root(3);
    TreeNode c1(9);
    TreeNode c2(20);
    TreeNode c3(15);
    TreeNode c4(7);
    TreeNode c5(8);
    root.left = &c1;
    root.right = &c2;
    c2.left = &c3;
    c2.right = &c4;
    c4.right = &c5;
    std::string s = Solution::serialize(nullptr);
    TreeNode *node = Solution::deserialize(s);
    cout << Solution::serialize(node) ;
    Solution::destroy(node);
}*/
