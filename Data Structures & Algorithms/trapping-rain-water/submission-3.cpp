class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        vector<int>leftMax(size, 0);
        vector<int>rightMax(size, 0);

        int lm = 0;
        int rm = 0;
        for(int i=0; i<size; i++){
            lm = max(lm, height[i]);
            leftMax[i] = lm;
            //lm = max(lm, height[i]);

            rm = max(rm, height[size-i-1]);
            rightMax[size-1-i] = rm;
            //rm = max(rm, height[size-i-1]);
        }

        for(int i=0; i<size; i++){
            //ans += max(0, min(leftMax[i], rightMax[i]) - height[i]);
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return  ans;
    }
};
