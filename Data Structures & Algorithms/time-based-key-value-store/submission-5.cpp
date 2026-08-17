class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int t) {
        auto& temp = mp[key];

        //sort(temp.begin(), temp.end()); We dont need to sort the vector cause it is added based on the timestamp so it is already sorted based on that

        int size = temp.size();
        int left = 0; 
        int right = size-1;

        string result = "";
        while(left <= right){
            int mid = left + (right-left)/2;
            if(temp[mid].first == t) return temp[mid].second;
            else if(t > temp[mid].first){ 
                result =  temp[mid].second;
                left = mid+1;
            }
            else right = mid-1;
        }
        return result;
    }
};
