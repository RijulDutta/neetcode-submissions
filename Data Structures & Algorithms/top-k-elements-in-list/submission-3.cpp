class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        for(int it: nums){
            mp[it]++;
        }

        for(auto it: mp){
            pair<int, int>p;
            p.first = it.second;
            p.second = it.first;

            pq.push(p);

            if(pq.size() > k){
                pq.pop();
            }
        }

        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
