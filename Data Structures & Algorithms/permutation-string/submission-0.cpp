class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size = s1.size();
        vector<int>hash1(26, 0);
        

        for(int i=0; i<s1.size(); i++){
            hash1[s1[i] - 'a']++;
        }

        int left = 0;

        vector<int>hash2(26, 0);
        for(int right=0; right<s2.size(); right++){
            if(right - left + 1 > size){
                hash2[s2[left] - 'a']--;
                left++;
            } 

            hash2[s2[right] - 'a']++;
            if(hash1 == hash2) return true;        
        }
        return false;
    }
};
