#include <stdexcept>
#include <string>
#include <iostream>
#include <dlfcn.h>

using namespace std;
typedef void (*MessageBoxA) (int, const char *, const char *, int);

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
    static const int WHATEVER = -1;
    static string serialize(TreeNode *);
    static TreeNode * deserialize(string &); 
    static void destroy (TreeNode *);
    /*
     * @param root: The root of the binary search tree.
     * @param value: destroy the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    static TreeNode * destroyNode(TreeNode * root, int value) {
        // write your code here
        if (!root) return nullptr;
        
        TreeNode *cur = root;
        enum Child {
            Left, Right
        };
        typedef pair<TreeNode *, Child> pairType;
        TreeNode virtual_node = TreeNode(WHATEVER);
        virtual_node.left = root;
        pairType parent = pairType(&virtual_node, Left);

        while (cur) {
            if (cur->val == value) {
                #define do_remove(rep) /* remove cur */ { \
                    if (parent.second == Left) \
                        parent.first->left = rep; \
                    else parent.first->right = rep; \
                    delete cur; \
                }

                
                if (cur->left && cur->right) {
                    TreeNode *biggestInLeft = cur->left, 
                             *parentOfBiggest = cur;
                    while (biggestInLeft->right) {
                        parentOfBiggest = biggestInLeft;
                        biggestInLeft = parentOfBiggest->right;
                    }
                    
                    int biggestVal = biggestInLeft->val;
                    if (parentOfBiggest->val == biggestInLeft->val)
						throw runtime_error("Duplicated values");
                    destroyNode(parentOfBiggest, biggestInLeft->val);
                    cur->val = biggestVal;
                    
                } else if (cur->left) {
                    do_remove(cur->left);
                } else if (cur->right) {
                    do_remove(cur->right);
                } else  {
                    do_remove(nullptr);
                }
                    
                break;
                #undef do_remove
            } else if (cur->val < value) {
                parent = pairType(cur, Right);
                cur = cur->right;
            } else  {
                parent = pairType(cur, Left);
                cur = cur->left;
            }
        }

        return virtual_node.left;
    }
};

int main () {
    string line;
    int removal;
    
    getline(cin, line);
    cin >> removal; cin.get();
    
    TreeNode *root = Solution::deserialize(line);
	try {
		root = Solution::destroyNode(root, removal);
	} catch (runtime_error err) {
		static void *hdl = dlopen("/cygdrive/c/Windows/System32/user32.dll", RTLD_LAZY);
		if (hdl)
			((MessageBoxA)dlsym(hdl, "MessageBoxA"))(0, err.what(), "Error", 0x10);
		cout << "Err: " << err.what() << endl;
	}
    
    cout << Solution::serialize(root) << endl;
    Solution::destroy(root);
    
    cin.get();
}
