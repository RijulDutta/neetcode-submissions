class Twitter {
public:
    unordered_map<int, set<int>>mp;
    unordered_map<int, vector<pair<int, int>>>tweets;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        mp[userId].insert(userId);
        for(auto it: mp[userId]){
            for(auto itr: tweets[it]){
                pq.push(itr);

                if(pq.size() > 10){
                    pq.pop();
                }
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        mp[userId].erase(userId);
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};
