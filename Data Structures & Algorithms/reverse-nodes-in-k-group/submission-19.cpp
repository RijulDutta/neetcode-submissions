class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;

        while(true){
            ListNode* end = groupPrev;
            for(int i = 0; i < k; i++){
                end = end->next;
                if(end == nullptr) return dummy->next;   // not enough nodes left, stop
            }

            ListNode* groupStart = groupPrev->next;
            ListNode* nextGroupStart = end->next;

            // reverse the group in place
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;
            while(curr != nextGroupStart){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            groupPrev->next = end;      // connect previous group to new head of this group
            groupPrev = groupStart;     // this node is now the tail of the reversed group
        }
    }
};