class Solution {
public:
    string minWindow(string s, string t) {
        int minSize = INT_MAX;
        string ans;
        int s_size = s.size();
        int t_size = t.size();
        unordered_map<char, int>mp;

        for(char c: t){
            mp[c]--;
        }

        int left = 0;
        int count = 0;
        for(int right=0; right<s_size; right++){
            if(mp[s[right]] < 0) count++;
            mp[s[right]]++;

            while(count == t_size){
                if(mp[s[left]] == 0) count--;
                mp[s[left]]--;
                left++;
            }

            int length = (right-left+1)+1;
            if(left-1>=0 && length < minSize){
                minSize = length;
                ans = s.substr(left-1, length);
            }
        }

        return ans;
    }
};
