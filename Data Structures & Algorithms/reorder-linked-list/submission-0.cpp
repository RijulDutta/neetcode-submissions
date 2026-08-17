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

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* list1 = head;
        ListNode* list2 = reverse(slow->next);
        slow->next = nullptr;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(list1 && list2){
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }

        if(list1) temp->next = list1;

        head = dummy->next;
    }

    ListNode* reverse(ListNode* head){
        if(head == nullptr) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
