/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* Bh(vector<int> num, int left, int right){
        if (left > right){
            return nullptr;
        }
        int mid = left + (right - left) / 2;

        TreeNode* node = new TreeNode(num[mid]);

        node->left = Bh(num, left, mid - 1);
        node->right = Bh(num, mid + 1, right);

        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector <int> num;
        while(head!= nullptr){
            num.push_back(head ->val);
            head = head->next;
        }
        return Bh(num, 0, num.size()-1);
    }
};