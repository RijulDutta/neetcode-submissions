using DLL = list<pair<int, int>>;

class LRUCache {
public:
    DLL l;
    int capacity;
    unordered_map<int, DLL::iterator>mp;  

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        auto it = mp[key];
        int val = it->second;
        l.erase(it);
        l.push_back({key, val});
        mp[key] = --l.end();

        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            auto it = mp[key];
            l.erase(it);
            l.push_back({key, value});
            mp[key] = --l.end();
        }else{
            l.push_back({key, value});
            mp[key] = --l.end();

            if(l.size() > capacity){
                mp.erase(l.front().first);
                l.pop_front();
            }
        }
    }
};
