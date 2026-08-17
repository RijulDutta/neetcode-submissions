class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, 0);
        int prod = 1;
        for(int i=0; i<size; i++){
            ans[i] = prod;
            prod *= nums[i];
        }

        prod = 1;
        for(int i=size-1; i>=0; i--){
            ans[i] = ans[i] * prod;
            prod *= nums[i];
        }

        return ans;
    }
};