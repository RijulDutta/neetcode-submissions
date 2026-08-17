class Solution {
public:
    vector<vector<string>>ans;
    int size;
    vector<vector<string>> partition(string s) {
        size = s.size();
        vector<string>inter;
        helper(s, inter, 0);
        return ans;
    }

    void helper(string&s, vector<string>&inter, int start){
        if(start == size){
            ans.push_back(inter);
            return;
        }

        for(int i=start+1; i<=s.size(); i++){
            string str = s.substr(start, i-start);
            if(!isPalindrome(str)) continue;

            inter.push_back(str);
            helper(s, inter, i);
            inter.pop_back();
        }
    }

    bool isPalindrome(string s){
        int left = 0;
        int right = s.size()-1;

        while(left <= right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
