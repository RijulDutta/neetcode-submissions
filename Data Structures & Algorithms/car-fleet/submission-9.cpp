class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double>mp;
        int n = position.size();
        stack<double>s;

        for(int i=0; i<n; i++){
            int dist_left = target - position[i];
            mp[dist_left] = (double)dist_left/speed[i];
        }

        for(auto it: mp){
            if(s.empty() || it.second > s.top()){
                s.push(it.second);
            }
        }

        return s.size();
    }
};
