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

        for(auto it : m)
        {
            if(it.second != 0) return false;
        }
        return true;
    }
};
