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
    void post_ord(vector<int>& postorder, TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        
        post_ord(postorder, root -> left);
        post_ord(postorder, root->right);
        postorder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        post_ord(postorder, root);
        return postorder;
    }
};