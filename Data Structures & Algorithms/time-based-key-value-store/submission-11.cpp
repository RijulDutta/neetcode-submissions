class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& temp = mp[key];

        int size = temp.size();
        int left = 0;
        int right = size-1;

        string result = "";
        while(left <= right){
            int mid = left + (right-left)/2;

            if(timestamp == temp[mid].first) return temp[mid].second;
            else if(timestamp > temp[mid].first){
                result = temp[mid].second;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return result;
    }
};
