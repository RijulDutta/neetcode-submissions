class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prevLesser(n);
        vector<int>nextLesser(n);
        
        stack<int>st1;
        for(int i=0; i<n; i++){
            while(!st1.empty() && heights[i] <= heights[st1.top()]){
                st1.pop();
            }
            if(st1.empty()) prevLesser[i] = -1;
            else prevLesser[i] = st1.top();

            st1.push(i);
        }

        stack<int>st2;
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && heights[i] <= heights[st2.top()]){
                st2.pop();
            }
            if(st2.empty()) nextLesser[i] = n;
            else nextLesser[i] = st2.top();

            st2.push(i);
        }

        int maxArea = INT_MIN;
        for(int i=0; i<n; i++){
            int area = heights[i] * (nextLesser[i] - prevLesser[i]-1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
