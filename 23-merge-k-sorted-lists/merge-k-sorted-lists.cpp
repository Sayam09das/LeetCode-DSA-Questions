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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;

        for (ListNode* head : lists) {
            while (head != nullptr) {
                v.push_back(head->val);
                head = head->next;
            }
        }
        sort(v.begin(), v.end());

        ListNode* d = new ListNode(0); // create a dummy new node;
        ListNode* curr = d;

        for (int i : v) {
            curr->next = new ListNode(i);
            curr = curr->next;
        }

        return d->next;
    }
};