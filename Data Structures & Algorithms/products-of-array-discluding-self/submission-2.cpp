class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>vec(size);

        int product = 1;
        for(int i=0; i<size; i++){
            vec[i] = product;
            product *= nums[i];
        }

        product = 1;
        for(int i=size-1; i>=0; i--){
            vec[i] *= product;
            product *= nums[i];
        }

        return vec;
    }
};
