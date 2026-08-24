/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*>mp;

        Node* dummy = new Node(0);
        Node* temp = dummy;

        while(head != nullptr){
            if(mp.find(head) == mp.end()){
                mp[head] = new Node(head->val);
            }
            Node* newHead = mp[head]; 

            if(head->next){
                if(mp.find(head->next) == mp.end()){
                    mp[head->next] = new Node(head->next->val);
                }
                newHead->next = mp[head->next];
            }

            if(head->random){
                if(mp.find(head->random) == mp.end()){
                    mp[head->random] = new Node(head->random->val);
                }
                newHead->random = mp[head->random];
            }

            temp->next = newHead;
            temp = temp->next;
            head = head->next;
        }

        return dummy->next;
    }
};
