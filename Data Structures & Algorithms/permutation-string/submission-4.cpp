class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();

        vector<int>hash1(26, 0);
        vector<int>hash2(26, 0);

        for(char c: s1){
            hash1[c - 'a']++;
        }

        int left = 0;
        for(int right=0; right<size2; right++){
            if(right < size1-1){
                hash2[s2[right] - 'a']++;
                continue;
            }

            hash2[s2[right] - 'a']++;
            if(hash1 == hash2) return true;
            else{
                hash2[s2[left] - 'a']--;
                left++;
            }
        }

        return false;
    }
};
