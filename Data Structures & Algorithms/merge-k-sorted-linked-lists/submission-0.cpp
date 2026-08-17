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
            pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()){
            ListNode* node = pq.top().second;
            pq.pop();
            if(node->next) pq.push({node->next->val, node->next});
            head->next = node;
            head = head->next;
        }
        head->next = nullptr;

        return dummy->next;
    }
};
