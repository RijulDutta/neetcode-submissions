class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        vector<int>inter(size+1);
        helper(digits, inter, size, 1);

        if(inter[0] == 0){
            vector<int>ans(inter.begin()+1, inter.end());
            return ans;
        }
        return inter;
    }

    void helper(vector<int>&digits, vector<int>&inter, int back, int carry){
        if(back == 0){
            inter[0] = carry;
            return;
        }

        if(digits[back-1] == 9 && carry == 1){
            inter[back] = 0;
            helper(digits, inter, back-1, 1);
            return;
        }

        inter[back] = digits[back-1] + carry;
        helper(digits, inter, back-1, 0);
    }
};
