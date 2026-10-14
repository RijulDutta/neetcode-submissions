class Solution {
public:
    vector<string>ans;
    vector<string> generateParenthesis(int n) {
        string inter = "";
        helper(n, inter, 0, 0);
        return ans;
    }

    void helper(int n, string inter, int open, int close){
        if(open == n && close == n){
            ans.push_back(inter);
            return;
        }

        if(open < n){
            inter.push_back('(');
            helper(n, inter, open+1, close);
            inter.pop_back();
        }

        if(close < open){
            inter.push_back(')');
            helper(n, inter, open, close+1);
            inter.pop_back();
        }
    }
};
