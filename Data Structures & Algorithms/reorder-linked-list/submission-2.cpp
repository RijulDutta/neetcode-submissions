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
        ListNode* list2 = slow->next;
        slow->next = nullptr;
        ListNode* list1 = head;

        list2 = reverse(list2);

        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        while(list1 && list2){
            ans->next = list1;
            list1 = list1->next;
            ans = ans->next;

            ans->next = list2;
            list2 = list2->next;
            ans = ans->next;
        }

        if(list1){
            ans->next = list1;
        }
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
