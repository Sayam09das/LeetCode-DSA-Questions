/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;

    void twoside(TreeNode* root, string path){
        if(root==nullptr)return;

        if(path.empty()){
            path = to_string(root->val);
        }
        else{
            path += "->" + to_string(root->val);
        }

        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(path);
            return;
        }

        twoside(root->left, path);
        twoside(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        twoside(root, "");
        return ans;
    }
};