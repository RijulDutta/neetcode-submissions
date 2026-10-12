class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<int>st;
        int size = s.size();
        int left = 0;

        for(int right = 0; right<size; right++){
            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            ans = max(ans, right-left+1);
        }

        return ans;
    }
};
