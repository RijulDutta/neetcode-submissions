using DLL = list<pair<int, int>>;//list<pair<key, val>>

class LRUCache {
public:
    DLL l;
    int capacity;
    unordered_map<int, DLL::iterator>mp; //map<key, pointer to nodein the list>

    LRUCache(int capacity) {
        this->capacity = capacity; 
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        auto temp = mp[key];
        int val = temp->second;
        l.erase(temp);
        l.push_back({key, val});
        mp[key] = --l.end();
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            auto temp = mp[key];
            l.erase(temp);
            l.push_back({key, value});
            mp[key] = --l.end();
        } 
        else{
            l.push_back({key, value});
            if(l.size() > capacity){
                mp.erase(l.front().first);
                l.pop_front();
            }
            mp[key] = --l.end();
        }
    }
};
