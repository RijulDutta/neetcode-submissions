class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>>tweets;//map<userId, vector<pair<time, tweetId>>>
    unordered_map<int, unordered_set<int>>fol; //set<followee, set<follower>>
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> followers = fol[userId];
        followers.insert(userId);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto it: followers){
            int size = tweets[it].size();
            
            for(int i=0; i<min(10, size); i++){
            //for(auto i: tweets[it]){
                pq.push(tweets[it][size-i-1]);
                if(pq.size() > 10){
                    pq.pop();
                }
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fol[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fol[followerId].erase(followeeId);
    }
};
