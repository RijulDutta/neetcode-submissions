class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int size = s.size();
        vector<int>hash(26, 0);
        int left = 0;

        for(int right=0; right<size; right++){
            hash[s[right] - 'A']++;

            while (left <= right){
                int maxi = 0;
                for(int i=0; i<26; i++){
                    maxi = max(maxi, hash[i]);
                }

                if(right-left+1 - maxi > k){
                    hash[s[left] - 'A']--;
                    left++;
                }else{
                    ans = max(ans, right-left+1);
                    break;
                }
            }
        }
        return ans;
    }
};
