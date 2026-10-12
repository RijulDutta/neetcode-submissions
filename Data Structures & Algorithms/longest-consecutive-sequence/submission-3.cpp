class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int>s;

        for(int num: nums){
            s.insert(num);
        }

        for(int i=0; i<nums.size(); i++){
            int curr = nums[i];
            if(s.find(curr-1) != s.end()) continue;

            int start = curr;
            int size = 1;
            while(s.find(start+1) != s.end()){
                start++;
                size++;
            }
            ans = max(ans, size);
        }
        return ans;
    }
};
