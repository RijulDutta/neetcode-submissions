class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        stack<string>st;

        for(string s: tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int num1 = stoi(st.top()); st.pop();
                int num2 = stoi(st.top()); st.pop();
                int result = getResult(num1, num2, s);
                st.push(to_string(result));
            }else{
                st.push(s);
            }
        }
        return stoi(st.top());
    }

    int getResult(int num1, int num2, string op){
        switch(op[0]){
            case '+': return num2+num1;
            case '-': return num2-num1;
            case '*': return num2*num1;
            case '/': return num2/num1;
        }
        return -1;
    }
};
