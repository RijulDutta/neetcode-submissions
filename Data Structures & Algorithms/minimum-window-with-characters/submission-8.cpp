class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,  int>mp;
        int mini = INT_MAX;
        int s_size = s.size();
        int t_size = t.size();
        string minStr;

        for(char c: t){
            mp[c]--;
        }
        
        int left = 0;
        int count = 0;
        for(int right=0; right<s_size; right++){
            if(mp[s[right]] < 0) count++;
            mp[s[right]]++;

            while(count == t_size){

                if(mp[s[left]] == 0){
                    count--;
                } 
                mp[s[left]]--;
                left++;
            }            

            int len = (right - left + 1) +1;
            if(left-1 >= 0 && len < mini){
                mini = len;
                minStr = s.substr(left-1, len);
            }
        }
        return minStr;
    }
};
