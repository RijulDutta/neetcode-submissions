class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>hash1(26, 0);
        vector<int>hash2(26, 0);

        for(int i=0; i<s.size(); i++){
            hash1[s[i]-'a']++;
        }

        for(int i=0; i<t.size(); i++){
            hash2[t[i]-'a']++;
        }

        if(hash1 == hash2) return true;
        return false;
    }
};
