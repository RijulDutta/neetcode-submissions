class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n; i++){
            int left = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);

                    left++;
                    right--;
                }else if(sum < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }

        vector<vector<int>>vec(ans.begin(), ans.end());
        return vec;
    }
};
