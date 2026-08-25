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
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        int carry = 0;

        while(l1 || l2){
            int sum;
            if(l1 && l2){ 
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1){ 
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else{
                sum = l2->val + carry;
                l2 = l2->next;
            }

            int digit = sum%10;
            carry = sum/10;

            ListNode* newNode = new ListNode(digit);
            head->next = newNode;
            head = head->next;
        }

        if(carry != 0){
            head->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
