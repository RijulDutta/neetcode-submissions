class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        
        int size = nums.size();
        if(size < 3) return {};

        sort(nums.begin(), nums.end());

        for(int i=0; i<size-2; i++){        
            int left = i+1;
            int right = size-1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    ans.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }else if(sum > 0){
                    right--;
                }else{
                    left++;
                }
            }
        }

        vector<vector<int>>fans(ans.begin(), ans.end());
        return fans;
    }
};
