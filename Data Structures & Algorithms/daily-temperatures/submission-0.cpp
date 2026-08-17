class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st; //decreasing stack  
        int size = t.size();
        vector<int>ans(size, 0);
        for(int i=size-1; i>=0; i--){
            while(!st.empty() && t[i] >= t[st.top()]){
                st.pop();
            }   

            if(!st.empty()) ans[i] = st.top() - i;

            st.push(i);
        }
        return ans;
    }
};
