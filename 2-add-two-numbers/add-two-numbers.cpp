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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        int carry = 0;
        int sum = 0;
        while(n1 != nullptr && n2 != nullptr){
            int sum = n1->val + n2->val + carry;
            int digit = sum;

            if(sum > 9){
                carry = sum / 10;
                digit = sum % 10;
            }else{
                carry = 0;
            }

            ListNode* newNode = new ListNode(digit);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }

            n1= n1-> next;
            n2=n2-> next;
        }


        while(n1 != nullptr){
            int sum = n1->val + carry;
            int digit = sum;

            if(sum > 9){
                carry = sum / 10;
                digit = sum % 10;
            }else{
                carry = 0;
            }

            ListNode* newNode = new ListNode(digit);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }

            n1=n1->next;
        }


        while(n2 != nullptr){
            int sum = n2->val + carry;
            int digit = sum;

            if(sum > 9){
                carry = sum / 10;
                digit = sum % 10;
            }else{
                carry = 0;
            }

            ListNode* newNode = new ListNode(digit);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }

            n2=n2-> next;
        }

        if(carry == 1){
            ListNode* newNode = new ListNode(carry);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        return head;
    }
};