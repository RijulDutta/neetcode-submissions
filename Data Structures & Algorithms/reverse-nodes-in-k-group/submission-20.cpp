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
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return dummy->next;

        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* last = nullptr;
        for(int i=0; i<k; i++){
            if(fast){
                last = fast;
                fast = fast->next;
            } else{
                temp->next = head;
                return dummy->next;
            }
        }

        last->next = nullptr;
        ListNode* append = reverse(slow);
        temp->next = append;
        temp = slow;

        return reverseKGroup(fast, k);
    }

    ListNode* reverse(ListNode* head){
        if(head == nullptr) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
