class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double>mp; //map<pair<dist_left, speed>, time_to_reach>
        stack<double> st;// monotonic increasing

        int n = position.size();

        for(int i=0; i<n; i++){
            int dist_left = target-position[i];
            mp[dist_left] = (double)dist_left/speed[i]; 
        }

    
        for(auto it: mp){
            if(st.empty() || it.second > st.top()){
                st.push(it.second);
            }
        }

        return st.size();
    }
};
