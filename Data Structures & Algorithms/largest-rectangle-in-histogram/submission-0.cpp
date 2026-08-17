class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int size = heights.size();

        vector<int>prevLesser(size, -1);
        vector<int>nextLesser(size, size);

        stack<int>st; //monotonic increasing 

        for(int i=0; i<size; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()) prevLesser[i] = st.top();
            st.push(i);
        }

        stack<int> s;
        for(int i=size-1; i>=0; i--){
            while(!s.empty() && heights[i] <= heights[s.top()]){
                s.pop();
            }
            if(!s.empty()) nextLesser[i] = s.top();
            s.push(i); 
        }

        for(int i=0; i<size; i++){
            int area = heights[i] * (nextLesser[i] - prevLesser[i] - 1);
            ans = max(ans, area);
        }

        return ans;
    }
};