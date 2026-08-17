class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m;
        
        for(char ch : s){
            m[ch]++;
        }

        for(char ch : t){
            m[ch]--;
        }

        for(auto const& [key, val] : m)
        {
            if(val != 0) return false;
        }
        return true;
    }
};
