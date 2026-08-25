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
        Node* traversal = head;

        while(traversal != nullptr){
            if(mp.find(traversal) == mp.end()){
                Node* newHead = new Node(traversal->val);
                mp[traversal] = newHead;
            }
            temp->next = mp[traversal];

            if(mp.find(traversal->next) == mp.end()){
                if(traversal->next){
                    Node* next = new Node(traversal->next->val);
                    mp[traversal->next] = next;
                }
                else{
                   mp[traversal->next] = nullptr;
                }
            }
            temp->next->next = mp[traversal->next];

            if(mp.find(traversal->random) == mp.end()){
                if(traversal->random){
                    Node* random = new Node(traversal->random->val);
                    mp[traversal->random] = random;
                }
                else{
                    mp[traversal->random] = nullptr;
                }
            }
            temp->next->random = mp[traversal->random];

            traversal = traversal->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
