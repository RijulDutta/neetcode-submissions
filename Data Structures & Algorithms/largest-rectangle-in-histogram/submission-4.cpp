class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>previousLesser(n, -1);
        vector<int>nextLesser(n, n);

        stack<int>s1;
        for(int i=0; i<n; i++){
            while(!s1.empty() && heights[i] <= heights[s1.top()]){
                s1.pop();
            } 
            if(!s1.empty()) previousLesser[i] = s1.top();
            s1.push(i);
        }   

        stack<int>s2;
        for(int i=n-1; i>=0; i--){
            while(!s2.empty() && heights[i] <= heights[s2.top()]){
                s2.pop();
            }
            if(!s2.empty()) nextLesser[i] = s2.top();
            s2.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int area = (nextLesser[i] - previousLesser[i] - 1) * heights[i];
            ans = max(ans, area);
        }

        return ans;
    }
};
