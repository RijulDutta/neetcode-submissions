class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;

        for(string tok: tokens){
            if(tok != "+" && tok != "-" && tok != "*" && tok != "/"){
                st.push(tok);
            }else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string val = getVal(s1, s2, tok);
                st.push(val);
            }
        }

        return stoi(st.top());
    }

    string getVal(string s1, string s2, string op){
        int num1 = stoi(s1);
        int num2 = stoi(s2);

        char tok = op[0];
        switch(tok){ 
            case '+' : return to_string(num2+num1);
            case '-' : return to_string(num2-num1);
            case '*' : return to_string(num2*num1);
            case '/' : return (num1 == 0)? "0": to_string(num2/num1);
            default: return "0";
        }
    }
};
