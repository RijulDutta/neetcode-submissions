class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int count = 0;

        priority_queue<int>pq;
        stack<int>st;
        unordered_map<char, int>mp;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }

        for(auto [c, val]: mp){
            pq.push(val);
        }

        while(!pq.empty()){
            for(int i=0; i<k+1; i++){
                if(pq.empty()){
                    if(!st.empty()) count += k+1-i;
                    break;
                }
                int v = pq.top();
                pq.pop();
                if(v-1 != 0) st.push(--v);
                count++;
            }
            while(!st.empty()){
                pq.push(st.top());
                st.pop();
            }
        }

        return count;
    }
};
