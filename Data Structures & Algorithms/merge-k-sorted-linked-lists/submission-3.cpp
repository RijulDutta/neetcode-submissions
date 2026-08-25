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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;

        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        for(int i=0; i<lists.size(); i++){
            if(lists[i]) pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()){
            ListNode* temp = pq.top().second;
            pq.pop();
            if(temp->next) pq.push({temp->next->val, temp->next});
            head->next = temp;
            head = head->next;
        }

        head->next = nullptr;

        return dummy->next;
    }
};
