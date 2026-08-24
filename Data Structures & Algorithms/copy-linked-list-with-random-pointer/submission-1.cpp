class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> mp;

        Node* dummy = new Node(0);
        Node* temp = dummy;
        Node* cur = head;

        while(cur != nullptr){
            if(mp.find(cur) == mp.end()){
                mp[cur] = new Node(cur->val);
            }
            Node* newHead = mp[cur];

            if(cur->next){
                if(mp.find(cur->next) == mp.end()){
                    mp[cur->next] = new Node(cur->next->val);
                }
                newHead->next = mp[cur->next];
            }

            if(cur->random){
                if(mp.find(cur->random) == mp.end()){
                    mp[cur->random] = new Node(cur->random->val);
                }
                newHead->random = mp[cur->random];
            }

            temp->next = newHead;
            temp = temp->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};