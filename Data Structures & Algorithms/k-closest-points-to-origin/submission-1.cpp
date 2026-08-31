class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>>pq;

        for(auto it: points){
            int x = it[0];
            int y = it[1];
            double distance = sqrt(x*x + y*y);

            pq.push({distance, it});
            if(pq.size() > k){
                pq.pop();
            } 
        }

        vector<vector<int>>ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
