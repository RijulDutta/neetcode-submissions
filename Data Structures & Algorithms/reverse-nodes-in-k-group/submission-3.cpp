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
        if(!head) return nullptr;

        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        ListNode* f = head;

        while(true){
            ListNode* first = f;
            bool flag = true;

            for(int i=0; i<k-1; i++){
                if(f->next) f = f->next;
                else{
                    flag = false;
                    break;
                }  
            }
            ListNode* last = f;
            bool hasMore = true;

            if(f->next) f = f->next;
            else hasMore = false;

            last->next = nullptr;
            
            ListNode* h = first;
            if(flag){
                h = reverse(first);
            }
            ans->next = h;
            ans = first;

            if(!flag || !hasMore) break;
        }
        return dummy->next;
    }

    ListNode* reverse(ListNode* head){
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
