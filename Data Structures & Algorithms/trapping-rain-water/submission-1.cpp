class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);

        int maxHeight = 0;
        for(int i=0; i<n; i++){
            maxHeight = max(maxHeight, height[i]);
            left[i] = maxHeight;
        }

        maxHeight = 0;
        for(int i=n-1; i>=0; i--){
            maxHeight = max(maxHeight, height[i]);
            right[i] = maxHeight;
        }

        int totalWater = 0;
        for(int i=0; i<n; i++){
            totalWater += min(left[i], right[i]) - height[i];
        }

        return totalWater;
    }
};
