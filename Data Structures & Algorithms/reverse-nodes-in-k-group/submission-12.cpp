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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* traversal = head;

        for(int i=0; i<k-1; i++){
            if(traversal == nullptr) return head;
            traversal = traversal->next;
        }

        if(traversal == nullptr) return head; 

        ListNode* end = traversal;
        traversal = traversal->next;
        end->next = nullptr;

        ListNode* ans = reverse(start);
        start->next = reverseKGroup(traversal, k);
        return ans;
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
