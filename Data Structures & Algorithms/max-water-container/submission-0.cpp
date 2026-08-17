class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = 0;
        int size = heights.size();

        int left = 0; 
        int right = size - 1;

        while(left < right){
            int minHeight = min(heights[left], heights[right]);
            maxi = max(maxi, minHeight * (right-left));

            if(heights[left] <= heights[right]){
                left++;
            }else{
                right--;
            }
        }

        return maxi;
    }
};
