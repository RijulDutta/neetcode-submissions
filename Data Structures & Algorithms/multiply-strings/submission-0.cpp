class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> vec(num1.size()+num2.size(), 0);

        for(int i=0; i<num2.size(); i++){
            int d2 = num2[i] - '0';
            for(int j=0; j<num1.size(); j++){
                int d1 = num1[j] - '0';
                vec[i+j] += d1*d2;
            }
        }

        for(int i=0; i<vec.size()-1; i++){
            vec[i+1] += vec[i]/10;
            vec[i] %= 10; 
        }

        reverse(vec.begin(), vec.end());
        string ans = "";
        bool start = true;
        for(int it: vec){
            if(start && it == 0) continue;
            start = false;
            ans += it + '0';
        }

        return ans;
    }
};
