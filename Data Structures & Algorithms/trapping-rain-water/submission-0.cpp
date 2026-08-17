class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;

        int size = height.size();
        vector<int> leftMaxHeight(size, 0);
        vector<int> rightMaxHeight(size, 0);

        int maxHeight = 0;
        for(int i=0; i<size; i++){
            maxHeight = max(maxHeight, height[i]);
            leftMaxHeight[i] = maxHeight;
        }

        maxHeight = 0;
        for(int i=height.size()-1; i>=0; i--){
            maxHeight = max(maxHeight, height[i]);
            rightMaxHeight[i] = maxHeight;
        }

        for(int i=0; i<size; i++){
            sum += min(leftMaxHeight[i], rightMaxHeight[i]) - height[i];
        }

        return sum;
    }
};
