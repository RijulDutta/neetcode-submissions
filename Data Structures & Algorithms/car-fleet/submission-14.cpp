class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        map<int, double>mp; //<rem_dist, time_required>
        stack<double>st; 

        for(int i=0; i<n; i++){
            double time = (double)(target - position[i])/speed[i];
            mp[target-position[i]] = time;
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
