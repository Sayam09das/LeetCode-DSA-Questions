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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == nullptr && q == nullptr){ //check nodes == null 
            return true;
        }
        if(p == nullptr || q== nullptr){ //check one nodes == null, is other not
            return false;
        }

       
        if(p->val != q->val){ //check nodes value
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); //recursively check two nodes companre(p,q)
    }
};