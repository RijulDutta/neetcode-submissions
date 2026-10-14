class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {
        vector<string>inter;
        helper(s, inter, 0);
        return ans;
    }

    void helper(string s, vector<string>inter, int start){
        if(start == s.size()){
            ans.push_back(inter);
            return;
        }

        for(int i=start; i<s.size(); i++){
            string word = s.substr(start, i-start+1);

            if(!isPalindrome(word)) continue;

            inter.push_back(word);
            helper(s, inter, i+1);
            inter.pop_back();
        }
    }

    bool isPalindrome(string word){
        int left = 0;
        int right = word.size()-1;

        while(left < right){
            if(word[left] != word[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
