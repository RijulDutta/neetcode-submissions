class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;

        vector<int>hash1(26, 0);
        for(char c: s1){
            hash1[c - 'a']++;
        }

        vector<int>hash2(26, 0);
        for(int i=0; i<n; i++){
            hash2[s2[i] - 'a']++;
        }
        if(hash2 == hash1) return true;

        int left = 0;
        for(int right=n; right<m; right++){
            hash2[s2[right] - 'a']++;
            hash2[s2[left] - 'a']--;
            left++;

            if(hash2 == hash1) return true;            
        }
        return false;
    }
};
