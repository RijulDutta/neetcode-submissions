class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& vec = mp[key];

        int left = 0;
        int right = vec.size()-1;
        string ans;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(timestamp == vec[mid].first) return vec[mid].second;
            else if(timestamp > vec[mid].first){
                ans = vec[mid].second;
                left = mid+1;
            }
            else{
                right = mid-1;
            } 
        }
        return ans;
    }
};
