class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        int mini = INT_MAX;
        int s_size = s.size();
        int t_size = t.size();

        unordered_map<int, int> mp;
        for(char ch: t){
            mp[ch]--;
        }

        int count = 0;
        int left = 0;
        for(int right=0; right<s_size; right++){
            if(mp[s[right]] < 0){
                count++;
            }
            mp[s[right]]++;


            while(count == t_size){
                int len = right - left + 1;
                if(len < mini){
                    mini = len;
                    ans = s.substr(left, len);
                }

                if(mp[s[left]] == 0){
                    count--;
                }
                mp[s[left]]--;
                left++;
            }
        }

        return ans;
    }
};
