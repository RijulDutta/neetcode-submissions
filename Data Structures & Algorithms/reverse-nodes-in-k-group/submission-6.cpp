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
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        bool full = true;

        while(head != nullptr){
            ListNode* start = head;
            for(int i=0; i<k-1; i++){
                if(head->next) head = head->next;
                else{
                    full = false;
                    break;
                }
            }
            ListNode* end = head;
            head = head->next;
            end->next = nullptr;

            if(full == false){
                temp->next = start;
                break;
            }else{
                ListNode* newList = reverse(start);
                temp->next = newList;
                temp = start;
            }
        }

        return dummy->next;
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
