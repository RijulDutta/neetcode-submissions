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

        while(l1 && l2){
            int sum = l1->val + l2->val;

            head->next = new ListNode(sum);
            head = head->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1) head->next = l1;
        if(l2) head->next = l2;

        int carry = 0;
        ListNode* traversal = dummy->next;
        ListNode* last = nullptr;
        while(traversal){
            int sum = traversal->val + carry;
            traversal->val = sum%10;
            carry = sum/10;
            last = traversal;
            traversal = traversal->next;
        }

        if(carry == 1) {
            last->next = new ListNode(1);
        } 

        return dummy->next;
    }
};
