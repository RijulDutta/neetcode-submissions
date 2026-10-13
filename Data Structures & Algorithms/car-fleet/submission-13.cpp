class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        map<int, double>mp; //<rem_dist, time_required>
        stack<double>st; 

        for(int i=0; i<n; i++){
            int dist_left = target - position[i];
            mp[dist_left] = (double)(dist_left)/speed[i];
        }

        for(auto it: mp){
            if(st.empty()) st.push(it.second);
            else{
                if(it.second > st.top()){
                    st.push(it.second); 
                }   
            }
        }

        return st.size();
    }
};
