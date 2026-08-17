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

        Node* head_c = new Node(head->val);
        mp[head] = head_c;
        Node* start = head_c;

        while(head != nullptr){
            //Creating next which might be present
            if(head->next != nullptr){
                Node* next = head->next;
                if(mp.find(next) == mp.end()){
                    Node* next_c = new Node(next->val);
                    mp[next] = next_c;
                    head_c->next = next_c;
                }else{
                    head_c->next = mp[next];
                }
            }

            //Creating random which might be present
            Node* random = head->random;
            if(random == nullptr) head_c->random = nullptr; 
            else if(mp.find(random) == mp.end()){
                Node* random_c = new Node(random->val);
                mp[random] = random_c;
                head_c->random = random_c;
            }else{
                head_c->random = mp[random];
            }

            head = head->next;
            head_c = head_c->next;
        }

        return start;
    }
};
