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
        ListNode* it1 = l1;
        int size1 = 1;
        while(it1->next != nullptr){
            size1++;
            it1 = it1->next; 
        }

        ListNode* it2 = l2; 
        int size2 = 1;
        while(it2->next != nullptr){
            size2++;
            it2 = it2->next;
        }

        if(size1 < size2){
            for(int i=0; i<size2-size1; i++){
                ListNode* newNode = new ListNode(0);
                it1->next = newNode;
                it1 = it1->next;
            }
        }else{
            for(int i=0; i<size1-size2; i++){
                ListNode* newNode = new ListNode(0);
                it2->next = newNode;
                it2 = it2->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            int val = sum%10;
            carry = sum/10;

            ListNode* newNode = new ListNode(val);
            head->next = newNode;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(carry>0){
            ListNode* newNode = new ListNode(carry);
            head->next = newNode;
            head = head->next;
        }
        head->next = nullptr;

        return dummy->next;
    }
};
