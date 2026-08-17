class Solution {
public:
    int n;
    vector<string>ans;
    vector<string> generateParenthesis(int n) {
        this->n = n;
        string inter;
        helper(inter, 0, 0);
        return ans;
    }

    void helper(string& inter, int open, int close)
    {
        if(open == n && close == n){
            ans.push_back(inter);
            return;    
        }

        if(open < n){
            inter.push_back('(');
            helper(inter, open+1, close);
            inter.pop_back();
        }

        if(close < open){
            inter.push_back(')');
            helper(inter, open, close+1);
            inter.pop_back();
        }
    }
};
