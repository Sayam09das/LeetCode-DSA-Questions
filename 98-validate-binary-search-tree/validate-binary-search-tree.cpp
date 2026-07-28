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
    vector<int> var;
    void check_BST(TreeNode* root) {
        if (root == nullptr)
            return;
        check_BST(root->left);
        var.push_back(root->val);
        check_BST(root->right);
    }
    bool isValidBST(TreeNode* root) {
        check_BST(root);

        for (int i = 0; i < var.size() - 1; i++) {
            if (var[i] >= var[i+1]) {
                return false;
            }
        }
        return true;
    }
};