class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = INT_MIN;
        int n = heights.size();

        int left = 0;
        int right = n-1;

        while(left < right){
            int area = (right-left) * min(heights[left], heights[right]);
            maxi = max(maxi, area);

            if(heights[left] <= heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxi;
    }
};
