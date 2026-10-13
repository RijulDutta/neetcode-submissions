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
    unordered_map<Node*, Node*>mp;

    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        Node* temp = head;

        Node* dummy = new Node(0);
        Node* h = dummy;

        while(temp){
            Node* newNode;

            //Normal
            if(mp.find(temp) != mp.end()) newNode = mp[temp];
            else{
                newNode = new Node(temp->val);
                mp[temp] = newNode;
            }

            //Next
            if(temp->next == nullptr) newNode->next = nullptr;
            else if(mp.find(temp->next) != mp.end()) newNode->next = mp[temp->next];
            else{
                Node* newNext = new Node(temp->next->val);
                mp[temp->next] = newNext;
                newNode->next = newNext;
            }

            //Random
            if(temp->random == nullptr) newNode->random = nullptr;
            else if(mp.find(temp->random) != mp.end()) newNode->random = mp[temp->random];
            else{
                Node* newRandom = new Node(temp->random->val);
                mp[temp->random] = newRandom;
                newNode->random = newRandom;
            } 

            h->next = newNode;
            h = h->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
