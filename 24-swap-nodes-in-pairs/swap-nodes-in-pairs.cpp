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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* A = head;
        ListNode* B = head->next;
        ListNode* prev = nullptr;

        while (A != nullptr && B != nullptr) {

            // Check first swap value;
            ListNode* C = B->next;
            B->next = A;
            A->next = C;

            if (prev != nullptr) {
                prev->next = B;
            } else {
                head = B;
            }


            // check next swap value;
            prev = A;
            A = C;
            if (C != nullptr) {
                B = C->next;
            } else {
                B = nullptr;
            }
        }

        return head;
    }
};