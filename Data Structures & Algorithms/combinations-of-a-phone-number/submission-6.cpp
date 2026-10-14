class Solution {
public:
    vector<string>ans;
    unordered_map<char, string>mp;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string inter;
        helper(digits, inter, 0);
        return ans;
    }

    void helper(string& digits, string& inter, int index){
        if(index == digits.size()){
            ans.push_back(inter);
            return;
        }

        string word = mp[digits[index]];
        for(int i=0; i<word.size(); i++){
            inter.push_back(word[i]);
            helper(digits, inter, index+1);
            inter.pop_back();
        }
    }
};
