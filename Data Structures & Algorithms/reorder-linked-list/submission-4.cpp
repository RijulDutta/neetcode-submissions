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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ListNode* l2 = reverse(slow->next);
        slow->next = nullptr;
        ListNode* l1 = head;


        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;


        while(l1 && l2){
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;

            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }

        if(l1) temp->next = l1;
        else temp->next = nullptr;

        head = dummy->next;
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
