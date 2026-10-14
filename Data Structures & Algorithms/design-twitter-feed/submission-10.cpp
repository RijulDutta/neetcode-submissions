class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>>mp;
    unordered_map<int, unordered_set<int>>fmp;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        auto temp = fmp[userId];
        temp.insert(userId);

        for(int id: temp){
            for(auto it: mp[id]){
                pq.push(it);
                if(pq.size() > 10){
                    pq.pop();
                }
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fmp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fmp[followerId].erase(followeeId);
    }
};
