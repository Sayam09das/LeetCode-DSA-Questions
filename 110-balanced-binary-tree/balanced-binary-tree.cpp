#include <cmath>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        if (height == -1) {
            return false;
        } else {
            return true;
        }
    }
    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int lsh = getHeight(root->left);
        int rsh = getHeight(root->right);

        if (lsh == -1 || rsh == -1) {
            return -1;
        }

        if (abs(lsh - rsh) > 1) {
            return -1;
        }

        return 1 + max(lsh, rsh);
    }
};