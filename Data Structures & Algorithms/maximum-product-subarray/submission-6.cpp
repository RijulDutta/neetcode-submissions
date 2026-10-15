class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prefix = 1;
        int suffix = 1;
        int product = INT_MIN;
        for(int i=0; i<n; i++){
            prefix *= nums[i];
            suffix *= nums[n-i-1];

            product = max(product, max(prefix, suffix));

            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
        }

        return product;
    }
};
