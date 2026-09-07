class CountSquares {
public:
    map<vector<int>, int>mp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int ans = 0;
        for(auto it: mp){
            int qx = it.first[0];
            int qy = it.first[1];

            if(px == qx || py == qy){
                continue;
            } 

            if(abs(qx-px) == abs(qy - py) && mp.find({qx, py}) != mp.end() && mp.find({px, qy}) != mp.end()){
                ans += it.second * mp[{qx, py}] * mp[{px, qy}];
            }
        }
        return ans;
    }
};
